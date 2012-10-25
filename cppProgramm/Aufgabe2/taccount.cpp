#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "taccount.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
/* Wenn ein Objekt vom Typ taccount angelegt wird, wird bei dem
   dazugehoerigen customer die Anzahl der Accounts um 1 erhoeht */
taccount::taccount(tcustomer *customer, string accountNumber, string pin)
{
  set(customer, accountNumber, pin);
  customer->addAmountAccounts();
}

/* Destruktor */
/* Wenn ein Objekt vom Typ taccount zerstoert wird, wird bei dem
   dazugehoerigen customer die Anzahl der Accounts um 1 verringert */
taccount::~taccount()
{
  customer->deleteAmountAccounts();
}

void taccount::set(tcustomer *customer, string accountNumber, string pin)
{
  this -> customer = customer;
  this -> accountNumber = accountNumber;
  this -> pin = pin;
  this -> amountBookings = 0;
  tmoney amount;
}

void taccount::print()
{
  customer->print();
  cout << endl;
  cout << "Kontonummer      : " << accountNumber << endl;
  cout << "Anzahl Buchungen : " << amountBookings << endl;
  cout << "Kontostand       : "; amount.print();
}