#pragma once

#ifndef _APPEND_TO_FILE_
#define _APPEND_TO_FILE_

#include <fstream>
#include <string>
#include "Note.hpp"
#include "writeToFileEnd.cpp"

using namespace std;

void appendToFile(Note note, const char* filename) {
  ofstream toFile(filename, ios::app);

  WriteToFileEnd(toFile, note);

  toFile.close();
}

#endif