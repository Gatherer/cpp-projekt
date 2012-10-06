//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gründer Jessica, Dürrschmidt Clemens, Schlabeck Mirco
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : main file for our c++ projekt
//============================================================================

#include <iostream>
using namespace std;

#include <time.h>

#include "tdate.h"
#include "ttime.h"

int main()
{
  TDate D1, D2(3, 10, 2012);
  TTime T1, T2(16, 0);
  cout << "\nKlasse TDate:" << endl;
  cout << "Standardkonstruktor Heutiges Datum D1:   "; D1.print(); cout << endl;
  cout << "Konstruktor         Tag der Einheit (D2):"; D2.print(); cout << endl;

  cout << "\nKlasse TTime:" << endl;
  cout << "Standardkonstruktor Aktuelle Uhrzeit T1: "; T1.print(); cout << endl;
  cout << "Konstruktor         Uebungsbeginn (T2):  "; T2.print(); cout << endl;

  return 0;
}
