//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gr�nder Jessica, D�rrschmidt Clemens, Schlabeck Mirco
// Version     : 0.1
// Description : main file for our c++ projekt
//============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

#include "tdate.h"
#include "ttime.h"
#include "tmoney.h"
#include "tcustomer.h"
#include "taccount.h"

int main()
{
  tdate D1, D2(3, 10, 2012);
  ttime T1, T2(16, 0);
  tmoney M1, M2(17.28, "Dollar");
  tcustomer C1("Klaus", "Kleber", D1, "Luxenburger Strasse", "3a", "13593", "Berlin");
  taccount A1(&C1, "1234567890", "9999");
  
  cout << "\nKlasse TDate:" << endl;
  cout << "Standardkonstruktor Heutiges Datum D1              : "; D1.print(); cout << endl;
  cout << "Konstruktor         Tag der Einheit D2             : "; D2.print(); cout << endl << endl;

  cout << "\nKlasse TTime:" << endl;
  cout << "Standardkonstruktor Aktuelle Uhrzeit T1            : "; T1.print(); cout << endl;
  cout << "Konstruktor         Uebungsbeginn T2               : "; T2.print(); cout << endl << endl;

  cout << "Klasse TMoney:" << endl;
  cout << "Standardkonstruktor 0 Euro M1                      : "; M1.print();
  cout << "Konstruktor         17.28 Dollar M2                : "; M2.print(); cout << endl << endl;
                                    
  cout << "Klasse Tcustomer:" << endl;
  cout << "Klause Kleber   : "; C1.print(); cout << endl << endl;
  
  cout << "Klasse Taccount:" << endl;
  cout << "1234567890   : "; A1.print(); cout << endl << endl;
  
  getchar();

  return 0;
}
