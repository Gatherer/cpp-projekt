#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tcurrentaccount.h"
#include "taccount.h"
#include "tmoney.h"
#include "tbank.h"
#include "tdate.h"
#include "ttime.h"

/* Allgemeiner Konstruktor */
tcurrentaccount::tcurrentaccount(tcustomer *customer, tbank *bank, string accountNumber, string pin,
  tmoney dispo): taccount(customer, bank, accountNumber, pin, false)
{
  this -> dispo = dispo;
  customer->setAccount(this);
  bank->setBankaccount(this);
}

/* Destruktor */
tcurrentaccount::~tcurrentaccount()
{
  cout << "tcurrentaccount:          Girokonto           (KtoNr. " << taccount::get_accountNumber() << ") wird vernichtet!" << endl;
}

void tcurrentaccount::set_dispo(double amount)
{
  dispo.set_amount(amount);
}

void tcurrentaccount::printAccountStatement()
{
  taccount::printAccountStatement();
  cout << "max. Dispo: "; dispo.print(); cout << endl;
}