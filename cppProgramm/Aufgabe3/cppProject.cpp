//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gruender Jessica, Schlabeck Mirco
// Version     : 0.2
// Description : main file for our c++ projekt
//============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "tdate.h"
#include "ttime.h"
#include "tmoney.h"
#include "tcustomer.h"
#include "taccount.h"

void enter()
{
  cout << "Press enter to continue...";
  cin.get();
// fuer Linux
//  system("clear");

// fuer Windows
  system("cls");
}

taccount anlegenAccount(tcustomer *customer, string kontonummer, string pin) 
{
  taccount dummy(customer, kontonummer, pin);
  
  return dummy;
}

int main()
{
  /* Kunde 1 anlegen */
  tdate D2(3, 10, 2012);
  tcustomer C1("Klaus", "Kleber", D2, "Luxenburger Strasse", "3a", "13593", "Berlin");
  
  /* Ausgabe Kunde 1 */
  cout << "---------------------------" << endl;
  cout << "Ausgabe Kunde  : " << endl;
  cout << "Klaus Kleber   : " << endl; 
  cout << "---------------------------" << endl;
  C1.print(); cout << endl << endl;
  
  enter();
  /* Account 1 anlegen */
  {
    taccount A1(&C1, "1234567890", "1234");

    /* Ausgabe Konto 1 */
    cout << "---------------------------" << endl;
    cout << "Ausgabe Konto 1:" << endl;
    cout << "---------------------------" << endl;
    A1.print();
    cout << endl;
    
    cout << endl << "Ausgabe amountAccount (sollte 1 sein): " << C1.get_amountAccounts() << endl;
    enter();
    
    /* Account 2 anlegen */
    {
	  taccount A2(&C1, "0987654321", "4321");
      /* Ausgabe Konto 2 */
      cout << "---------------------------" << endl;
      cout << "Ausgabe Konto 2:" << endl;
      cout << "---------------------------" << endl;
      A2.print();
      cout << endl;
        
      cout << endl << "Ausgabe amountAccount (sollte 2 sein): " << C1.get_amountAccounts() << endl;
      enter();
    }
    /* Ausgabe Kunde 1 */
    cout << "---------------------------" << endl;
    cout << "Ausgabe Kunde:" << endl;
    cout << "Klause Kleber   : " << endl; 
    cout << "---------------------------" << endl;
    C1.print(); cout << endl << endl;
    
    /* Account 2 wird zerstört */
    cout << endl << "Ausgabe amountAccount: (sollte 1 sein): " << C1.get_amountAccounts() << endl;
    enter();
  }

  /* Account 1 wird zerstört */
  cout << endl << "Ausgabe amountAccount: (sollte 0 sein): " << C1.get_amountAccounts() << endl;
  enter();
  return 0;
}
