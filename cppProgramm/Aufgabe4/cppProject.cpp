//============================================================================
// Name        : cppProjekt.cpp
// Author      : Glatte, Thomas; Gruender Jessica, Schlabeck Mirko
// Version     : 0.4
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
#include "tcurrentaccount.h"
#include "tsavingsaccount.h"

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
  
  tbank *B1 = new tbank("Berliner Bank", "10020000");
  
  taccount             *A1 = new taccount(&C1, B1, "0", "0000");
  tcurrentaccount      *A2 = new tcurrentaccount(&C2, B1, "1234567890", "9999", tmoney(100.00));
  tsavingsaccount      *A3 = new tsavingsaccount(&C3, B1, "9876543210", "0101", 1.5);
  //tfixeddepositaccount *A4 = new tfixeddepositaccount(&C2, B1, "111333555", "1357", tmoney(100.00), 1.5);
  
  tbooking BU1(tmoney(150.0), A1, A2, tdate(), ttime(), "Startguthaben");
//  tbooking BU2(tmoney(50.0), A2, A4, tdate(), ttime(), "Umbuchung");
  tbooking BU3(tmoney(39.9), A2, A3, tdate(), ttime(), "Rechnung 4711");
  
  cout << "Kunde 1"<< endl; C2.print(); cout << endl;
  cout << "Kunde 2"<< endl; C3.print(); cout << endl;
  cout << "Bank 1" << endl; B1->print(); cout << endl;
  enter();
  
  for (int i = 0; i < B1->get_amountBankaccounts(); i++)
  {
//    cout << "adresse vor Bankauszug" << (B1->getAccount(i)) << endl;
    (B1->getAccount(i))->printAccountStatement();
    cout << endl;
  }
  
  cout << "Jetzt wird die Bank vernichtet und damit auch die Konten der Bank:" << endl;
  delete B1;
  
  enter();
  return 0;
}
