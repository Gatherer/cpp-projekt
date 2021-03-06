//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gruender Jessica, Schlabeck Mirko
// Version     : 0.3
// Description : main file for our c++ projekt
//============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "tbooking.h"
#include "tdate.h"
#include "ttime.h"
#include "tmoney.h"
#include "tcustomer.h"
#include "taccount.h"
#include "tbank.h"

void enter()
{
  cout << "Press enter to continue...";
  cin.get();
//  fuer Linux
  system("clear");

// fuer Windows
//  system("cls");
}

int main()
{
  tdate D1(7, 7, 1977);
  tdate D2(8, 8, 1988);
  
  tcustomer C1("Geldquelle", tdate(), "", "", "", "");
  tcustomer C2("Egon Muster", D1, "Mustergasse", "3a", "99899", "Musterstadt");
  tcustomer C3("Rudolf Rednose", D2, "Berliner Strasse", "17", "10999", "Berlin");
  
  tbank B1("Berliner Bank", "10020000");
  
  taccount A1(&C1, &B1, "0", "0000");
  taccount A2(&C2, &B1, "1234567890", "9999");
  taccount A3(&C3, &B1, "9876543210", "0101");
  taccount A4(&C2, &B1, "111333555", "1357");
  
  tbooking BU1(tmoney(150.0), &A1, &A2, tdate(), ttime(), "Startguthaben");
  tbooking BU2(tmoney(50.0), &A2, &A4, tdate(), ttime(), "Umbuchung");
  tbooking BU3(tmoney(39.9), &A2, &A3, tdate(), ttime(), "Rechnung 4711");
  
  cout << "Kunde 1"<< endl; C2.print(); cout << endl;
  cout << "Kunde 2"<< endl; C3.print(); cout << endl;
  cout << "Bank 1" << endl; B1.print(); cout << endl;
  enter();
  A2.printAccountStatement();
  cout << endl;
  A2.printAccountStatement();
  
  enter();
  return 0;
}
