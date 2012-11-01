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
  set(0.0, "EUR");
}

void tmoney::set(double amount, string currency)
{
  this -> amount = amount;
  this -> currency = currency;
}

void tmoney::print()
{
  cout << right << fixed << setprecision(2) << setw(11) << amount << " " << currency << flush;
//  cout << fixed << setprecision(2) << amount << " " << currency << flush;
}

void tmoney::sub(tmoney amountChange)
{
  amount = amount - amountChange.amount;
}

void tmoney::add(tmoney amountChange)
{
  amount = amount + amountChange.amount;
}