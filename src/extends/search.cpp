#pragma once

#ifndef _SEARCH_F_
#define _SEARCH_F_

#include "Note.hpp"
#include <string>

int Search(Note* notes, const int N, const std::string tel) {
  for (int i = 0; i < N; i++)
    if (notes[i].tel == tel)
      return i;

  return -1;
}

#endif