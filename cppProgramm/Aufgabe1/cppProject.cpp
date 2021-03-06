//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gruender Jessica, Schlabeck Mirco
// Version     : 0.1
// Description : main file for our c++ projekt
//============================================================================

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

#include "tdate.h"
#include "ttime.h"

int main()
{
  tdate D1, D2(3, 10, 2012);
  ttime T1, T2(16, 0);
  cout << "\nKlasse TDate:" << endl;
  cout << "Standardkonstruktor Heutiges Datum D1              : "; D1.print(); cout << endl;
  cout << "Konstruktor         Tag der Einheit D2             : "; D2.print(); cout << endl << endl;

  cout << "\nKlasse TTime:" << endl;
  cout << "Standardkonstruktor Aktuelle Uhrzeit T1            : "; T1.print(); cout << endl;
  cout << "Konstruktor         Uebungsbeginn T2               : "; T2.print(); cout << endl << endl;

  getchar();

  return 0;
}
