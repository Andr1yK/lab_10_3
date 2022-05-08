#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "extends/Note.hpp"
#include "extends/fill.cpp"
#include "extends/print.cpp"
#include "extends/search.cpp"
#include "extends/searchInFile.cpp"
#include "extends/loadFromFile.cpp"
#include "extends/saveToFile.cpp"
#include "extends/appendToFile.cpp"
#include "extends/getLineCountInFile.cpp"

using namespace std;

int main()
{
  setlocale(LC_CTYPE, "ukr");

  int N = 0;
  Note* notes = nullptr;
  Note* temp = nullptr;
  Note* fromFileStore = nullptr;

  Note forAutoFill[10] = {
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

  char filename[100];

  string findTel;
  int findedIndex;

  int menuItem;
  do {
    cout << endl << endl;
    cout << "Виберіть дію:" << endl << endl;
    cout << " [1] - введення даних з клавіатури" << endl;
    cout << " [2] - автоматичне введення даних" << endl;
    cout << " [3] - вивід даних на екран" << endl;
    cout << " [4] - пошук за номером" << endl;
    cout << " [5] - пошук за номером в файлі" << endl;
    cout << " [6] - зберегти дані в файл" << endl;
    cout << " [7] - загрузити дані з файлу" << endl;
    cout << " [8] - додати дані в файл" << endl;

    cout << endl;

    cout << " [0] - вихід та завершення роботи програми" << endl << endl;
    cout << "Введіть значення: "; cin >> menuItem;
    cout << endl << endl << endl;

    switch (menuItem)
    {
    case 1:
      cout << "Введіть N: "; cin >> N;
      notes = new Note[N];

      Fill(notes, N);
      break;

    case 2:
      cout << "Введіть N(max 10): "; cin >> N;
      if (N > 10)
        N = 10;

      temp = new Note[N];

      for (int i = 0; i < N; i++)
        temp[i] = forAutoFill[i];

      delete[] notes;
      notes = temp;
      break;

    case 3:
      Print(notes, N);
      break;

    case 4:
      cin.get(); cin.sync();

      cout << " Введіть номер телефону: "; getline(cin, findTel);

      if ((findedIndex = Search(notes, N, findTel)) >= 0)
        Print(&notes[findedIndex]);
      else
        cout << "Запис з таким телефонним номером не знайдено" << endl;

      break;
    
    case 5:
      cin.get(); cin.sync();

      cout << " Введіть ім'я файлу: "; cin.getline(filename, 99);
      cout << " Введіть номер телефону: "; getline(cin, findTel);

      if ((findedIndex = SearchInFile(filename, findTel)) >= 0)
        Print(&(LoadFromFile(filename, 1, findedIndex)[0]));
      else
        cout << "Запис з таким телефонним номером не знайдено" << endl;

      break;

    case 6:
      cin.get();
      cin.sync();

      cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);

      cout << N << endl;

      SaveToFile(notes, N, filename);
      
      break;

    case 7:
      cin.get();
      cin.sync();

      cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);

      N = getLineCountInFile(filename);

      delete[] notes;
      notes = LoadFromFile(filename, N);

      break;

    case 8:
      cin.get();
      cin.sync();

      cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);

      delete[] temp;
      temp = new Note[1];

      Fill(temp, 1);

      appendToFile(temp[0], filename);

      break;

    case 0:
      break;

    default:
      cout << "Ви ввели помилкове значення! "
        "Слід ввести число - номер вибраного пункту меню" << endl;
    }
  } while (menuItem != 0);

  return 0;
}
