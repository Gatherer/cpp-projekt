//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gründer Jessica, Dürrschmidt Clemens, Schlabeck Mirco
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
  s_ttime A1;
  s_tdate B1;

  tdate D1, D2(3, 10, 2012);
  ttime T1, T2(16, 0);
  cout << "\nKlasse TDate:" << endl;
  cout << "Standardkonstruktor Heutiges Datum D1              : "; D1.print(); cout << endl;
  cout << "Konstruktor         Tag der Einheit D2             : "; D2.print(); cout << endl << endl;

  D1.set(4, 5, 2000);
  cout << "D1 nach set                                        : "; D1.print(); cout << endl;

  B1 = D2.get();
  cout << setfill('0');	
  cout << "B1 nach D2 get                                     : "; cout << setw(2) << B1.day << ":" 
	                                                                    << setw(2) << B1.month << ":" 
																		<< setw(4) << B1.year << endl;

  cout << "\nKlasse TTime:" << endl;
  cout << "Standardkonstruktor Aktuelle Uhrzeit T1            : "; T1.print(); cout << endl;
  cout << "Konstruktor         Uebungsbeginn T2               : "; T2.print(); cout << endl << endl;

  T1.set(1, 2, 3);
  cout << "T1 nach set                                        : "; T1.print(); cout << endl;

  A1 = T2.get();
  cout << setfill('0');	
  cout << "A1 nach T2 get                                     : "; cout << setw(2) << A1.hour << ":" 
	                                                                    << setw(2) << A1.min << ":" 
																		<< setw(2) << A1.sec;

  getchar();

  return 0;
}
