//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gruender Jessica, Duerrschmidt Clemens, Schlabeck Mirco
// Version     : 0.2
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
  /* Kunde 1 anlegen */
  tdate D2(3, 10, 2012);
  tcustomer C1("Klaus", "Kleber", D2, "Luxenburger Strasse", "3a", "13593", "Berlin");
  
  /* Ausgabe Kunde 1 */
  cout << "---------------------------" << endl;
  cout << "Ausgabe Kunde:" << endl;
  cout << "Klause Kleber   : " << endl; 
  cout << "---------------------------" << endl;
  C1.print(); cout << endl << endl;
  
  /* Account 1 anlegen */
  {
    taccount A1(&C1, "1234567890", "9999");
  
	/* Ausgabe Konto 1 */
	cout << "---------------------------" << endl;
	cout << "Ausgabe Konto:" << endl;
    cout << "Testkonto 1 :" << endl; 
    cout << "---------------------------" << endl;
    A1.print();
	cout << endl;

	cout << endl << "Ausgabe amountAccount: " << C1.get_amountAccounts() << endl;
	getchar();
  }

  /* Account 1 wird zerstört */
  cout << endl << "Ausgabe amountAccount: " << C1.get_amountAccounts() << endl;
  getchar();
  return 0;
}
