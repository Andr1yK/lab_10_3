#pragma once

#ifndef _FILL_
#define _FILL_

#include <iostream>
#include "Note.hpp"

using namespace std;

void Fill(Note* notes, const int N)
{
  for (int index = 0; index < N; index++)
  {
    cout << "Запис № " << index + 1 << ":" << endl;

    cin.get(); cin.sync();

    cout << " Прізвище та ім'я: "; getline(cin, notes[index].fullName);
    cout << endl;
    cout << " Номер телефону: "; cin >> notes[index].tel;
    cout << endl;
    
    cout << " День народження  : "; cin >> notes[index].birthday[0];
    cout << " Місяць народження: "; cin >> notes[index].birthday[1];
    cout << " Рік народження   : "; cin >> notes[index].birthday[2];

    cout << endl;
  }
}

#endif
