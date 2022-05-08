#pragma once

#ifndef _PRINT_
#define _PRINT_

#include <iostream>
#include "Note.hpp"
#include <iomanip>

using namespace std;

void Print(Note* notes, const int N = 1)
{
#pragma region HEADER
  cout << "==============================================================="
    << endl;

  cout << setfill(' ') << right << "| " << setw(3) << "№" << " | "
    << setw(20) << left << "Прізвище, ім'я" << " | "
    << setw(12) << "Телефон" << " | "
    << setw(15) << "Дата народження" << " |"
    << endl;

  cout << "---------------------------------------------------------------"
    << endl;
#pragma endregion

  for (int i = 0; i < N; i++)
  {
    Note note = notes[i];

    cout << "| " << setw(3) << right << i + 1 << " | "
      << setw(20) << left << note.fullName << " |"
      << setw(13) << right << note.tel << " | ";

    cout << setfill('0') << right
      << setw(2) << to_string(note.birthday[0]) << "."
      << setw(2) << to_string(note.birthday[1])  << "." 
      << setw(4) << to_string(note.birthday[2]) 
      << setfill(' ') << setw(7) << " |"
      << endl;

    if (i < N - 1)
      cout << "---------------------------------------------------------------"
        << endl;
  }

  cout << "==============================================================="
    << endl;
  cout << endl;
}

#endif