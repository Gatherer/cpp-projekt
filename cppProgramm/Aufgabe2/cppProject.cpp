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
  tdate D2(3, 10, 2012);
  tmoney M1, M2(17.28, "Dollar");
  tcustomer C1("Klaus", "Kleber", D2, "Luxenburger Strasse", "3a", "13593", "Berlin");
  taccount A1(&C1, "1234567890", "9999");
                                    
  cout << "Ausgabe Kunde:" << endl;
  cout << "Klause Kleber   : " << endl; 
  cout << "---------------------------" << endl;
  C1.print(); cout << endl << endl;
  
  cout << "Ausgabe Konto:" << endl;
  cout << "Testkonto 1 :" << endl; 
  cout << "---------------------------" << endl;
  A1.print(); cout << endl << endl;
  
  getchar();

  return 0;
}
