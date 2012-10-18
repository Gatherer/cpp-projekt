#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tmoney.h"

/* Allgemeiner Konstruktor */
tmoney::tmoney(double amount, string currency)
{
  set(amount, currency);
}

/* Standardkonstruktor */
tmoney::tmoney()
{
  set(0, "Euro");
}

void tmoney::set(double amount, string currency)
{
  this -> amount = amount;
  this -> currency = currency;
}

void tmoney::print()
{
  cout << amount << " " << currency;
}
