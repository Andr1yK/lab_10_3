#pragma once

#ifndef _SEARCH_IN_FILE_
#define _SEARCH_IN_FILE_

#include <fstream>
#include "Note.hpp"

using namespace std;

int SearchInFile(const char* filename, const string tel) {
  ifstream fromFile(filename);

  string currentTel;
  string str;
  int pos;

  for (int index = 0; getline(fromFile, str); index++, pos = 0)
  {
    pos = str.find(", ", pos + 1);
    currentTel.assign(str, pos + 2, str.find(", ", pos + 1) - pos - 2);

    if (currentTel == tel) {
      return index;
    }
  }

  return -1;
}

#endif