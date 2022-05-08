#pragma once

#ifndef _GET_LINE_COUNT_IN_FILE_
#define _GET_LINE_COUNT_IN_FILE_

#include <fstream>
#include "Note.hpp"

using namespace std;

int getLineCountInFile(const char* filename) {
  ifstream file(filename);
  unsigned int count;
  string line;
  
  for(count = 0; getline(file, line); count++);

  file.close();

  return count;
}

#endif