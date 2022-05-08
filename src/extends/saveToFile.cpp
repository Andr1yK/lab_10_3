#pragma once

#ifndef _SAVE_TO_FILE_
#define _SAVE_TO_FILE_

#include <fstream>
#include <string>
#include "Note.hpp"
#include "writeToFileEnd.cpp"

using namespace std;

void SaveToFile(Note* notes, const int N, const char* filename)
{
  ofstream toFile(filename);

  for (int index = 0; index < N; index++) {
    WriteToFileEnd(toFile, notes[index]);
  };

  toFile.close();
}

#endif