#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "taccount.h"
#include "tmoney.h"

taccount::taccount(tcustomer customer, string number, string pin)
{
  set(customer, accountNumber, pin);
}

void taccount::set(tcustomer customer, string accountNumber, string pin)
{
  
  this -> customer = &customer;
  this -> accountNumber = accountNumber;
  this -> pin = pin;
  this -> amountBookings = 0;
  tmoney amount;
}

void taccount::print()
{
  &customer.print();
  cout << "Kontonummer      : " << accountNumber << endl;
  cout << "Anzahl Buchungen : " << amountBookings << endl;
  cout << "Kontostand       : "; amount.print(); cout << endl;
}