#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "../src/extends/Note.hpp"
#include "../src/extends/searchInFile.cpp"
#include "../src/extends/getLineCountInFile.cpp"
#include "../src/extends/writeToFileEnd.cpp"
#include "../src/extends/loadFromFile.cpp"
#include "../src/extends/appendToFile.cpp"

using namespace std;

const int N = 10;

struct WorkWithFile : public testing::Test
{
  char fname[30] = "unittests.temp.txt";
  ofstream fout;

  const int NotesCount = N;

  Note notes[N] = {
    {"Sheikh Barnard",    "380634161835", {14, 9,  2014} },
    {"Atlanta Gall",      "380925229621", {4, 12,  2020} },
    {"Uma Noble",         "380633648116", {21, 5,  1998} },
    {"Siddharth Ferry",   "380507585956", {7,  4,  1974} },
    {"Jaxon Leal",        "380506986742", {12, 8,  2000} },
    {"Santino Read",      "380683046862", {23, 3,  2010} },
    {"Shana Flores",      "380631996430", {17, 5,  1998} },
    {"Louisa Irwin",      "380503792270", {5,  9,  1974} },
    {"Anita Dominguez",   "380665919172", {1,  7,  2003} },
    {"Eathan Roach",      "380683038390", {7,  7,  2010} },
  };

  string notesRaw = "\
Sheikh Barnard, 380634161835, 14, 9, 2014\n\
Atlanta Gall, 380925229621, 4, 12, 2020\n\
Uma Noble, 380633648116, 21, 5, 1998\n\
Siddharth Ferry, 380507585956, 7, 4, 1974\n\
Jaxon Leal, 380506986742, 12, 8, 2000\n\
Santino Read, 380683046862, 23, 3, 2010\n\
Shana Flores, 380631996430, 17, 5, 1998\n\
Louisa Irwin, 380503792270, 5, 9, 1974\n\
Anita Dominguez, 380665919172, 1, 7, 2003\n\
Eathan Roach, 380683038390, 7, 7, 2010\n\
";

  void SetUp() override {
    fout.open(fname);

    fout << notesRaw;

    fout.close();
  }

  void TearDown() override {
    remove(fname);
  }
};

TEST_F(WorkWithFile, SearchInFile) {
  int actual;
  int expected = 7;
  
  actual = SearchInFile(fname, "380503792270");

  EXPECT_EQ(actual, expected);
};

TEST_F(WorkWithFile, SearchInFileNotExist) {
  int actual;
  int expected = -1;
  
  actual = SearchInFile(fname, "00000000");

  EXPECT_EQ(actual, expected);
};

TEST_F(WorkWithFile, GetLineCount) {
  int actual = NotesCount;
  int expected = 10;
  
  actual = getLineCountInFile(fname);

  EXPECT_EQ(actual, expected);
};

TEST_F(WorkWithFile, LoadOneNote) {
  Note* actual;
  Note* expected = &notes[0];
  
  actual = LoadFromFile(fname, 1);

  EXPECT_EQ(actual->fullName, expected->fullName);
};

TEST_F(WorkWithFile, LoadAllNotes) {
  Note* actual;
  Note* expected = notes;
  
  actual = LoadFromFile(fname, 10);

  for (int i = 0; i < NotesCount; i++)
    EXPECT_EQ(actual[i].fullName, expected[i].fullName);
};

TEST_F(WorkWithFile, LoadAllNotesGetLines) {
  Note* actual;
  Note* expected = notes;

  int lines = getLineCountInFile(fname);
  
  actual = LoadFromFile(fname, lines);

  for (int i = 0; i < NotesCount; i++)
    EXPECT_EQ(actual[i].fullName, expected[i].fullName);
};

TEST_F(WorkWithFile, WriteToEndFile) {
  Note* actual;
  Note* expected = new Note[NotesCount + 1];
  Note newNote = {"TEST", "3800000000000", {1, 1,  1970} };

  fout.open(fname, ios::app);

  for (int i = 0; i < NotesCount; i++)
    expected[i] = notes[i];

  expected[NotesCount] = newNote;

  WriteToFileEnd(fout, newNote);
  
  actual = LoadFromFile(fname, 11);

  for (int i = 0; i < NotesCount + 1; i++)
    EXPECT_EQ(actual[i].fullName, expected[i].fullName);
};

TEST_F(WorkWithFile, AppendFile) {
  Note* actual;
  Note* expected = new Note[NotesCount + 1];
  Note newNote = {"TEST", "3800000000000", {1, 1,  1970} };

  for (int i = 0; i < NotesCount; i++)
    expected[i] = notes[i];

  expected[NotesCount] = newNote;

  appendToFile(newNote, fname);
  
  actual = LoadFromFile(fname, 11);

  for (int i = 0; i < NotesCount + 1; i++)
    EXPECT_EQ(actual[i].fullName, expected[i].fullName);
}