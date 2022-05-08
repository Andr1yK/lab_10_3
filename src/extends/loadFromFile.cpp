#pragma once

#ifndef _LOAD_FROM_FILE_
#define _LOAD_FROM_FILE_

#include <fstream>
#include <string>
#include "Note.hpp"

using namespace std;

Note* LoadFromFile(const char* filename, unsigned int N, int startLine = 0)
{
  ifstream fromFile(filename);
  string str;

  Note* notes = new Note[N];

  int pos = 0;
  int posEnd = 0;
  int index = 0;
  int currentLine = 0;

  string tempLine;

  while (getline(fromFile, str) && index < N)
  {
    currentLine++;
    
    if (currentLine <= startLine)
      continue;

    posEnd = str.find(", ", pos + 1);
    notes[index].fullName.assign(str, pos, posEnd - pos);
    pos = posEnd;

    posEnd = str.find(", ", pos + 1);
    notes[index].tel.assign(str, pos + 2, posEnd - pos - 2);
    pos = posEnd;

    for (int i = 0; i < 3; i++) {
      posEnd = str.find(", ", pos + 1);
      notes[index].birthday[i] = stoi(tempLine.assign(str, pos + 2, posEnd - pos - 2));
      pos = posEnd;
    }

    index++;
    pos = 0;
  }

  fromFile.close();

  return notes;
}

#endif