#pragma once

#ifndef _WRITE_TO_FILE_END_
#define _WRITE_TO_FILE_END_

#include <fstream>
#include "Note.hpp"

using namespace std;

void WriteToFileEnd(ofstream &toFile, Note note) {
  int* date = note.birthday;

  toFile << note.fullName << ", "
    << note.tel << ", "
    << date[0] << ", "
    << date[1] << ", "
    << date[2]
    << endl;
}

#endif