#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tsavingsaccount.h"
#include "taccount.h"
#include "tmoney.h"
#include "tbank.h"
#include "tdate.h"
#include "ttime.h"

/* Allgemeiner Konstruktor */
tsavingsaccount::tsavingsaccount(tcustomer *customer, tbank *bank, string accountNumber, string pin,
  double zinsen): taccount(customer, bank, accountNumber, pin, false, 3)
{
  this -> zinsen = zinsen;
  customer->setAccount(this);
  bank->setBankaccount(this);
}

tsavingsaccount::tsavingsaccount(tcustomer *customer, tbank *bank, string accountNumber, string pin,
  double zinsen, int accountType): taccount(customer, bank, accountNumber, pin, false, 3)
{
  this -> zinsen = zinsen;
}

/* Destruktor */
tsavingsaccount::~tsavingsaccount()
{
  cout << "tsavingsaccount:          Sparkonto           (KtoNr. " << taccount::get_accountNumber() << ") wird vernichtet!" << endl;
}

void tsavingsaccount::set_zinsen(double zinsen)
{
  this -> zinsen = zinsen;
}

void tsavingsaccount::printAccountStatement()
{
  taccount::printAccountStatement();
  cout << "Zinssatz: " << setw(22) << right << zinsen << " %" << endl;
}

tmoney tsavingsaccount::get_possibleMoney()
{
  tmoney dummy;

  dummy.add(taccount::get_money());
  return dummy;
}