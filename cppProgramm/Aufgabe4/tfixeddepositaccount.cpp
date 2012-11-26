#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tfixeddepositaccount.h"
#include "tcurrentaccount.h"
#include "tsavingsaccount.h"
#include "taccount.h"
#include "tmoney.h"
#include "tbank.h"
#include "tdate.h"
#include "ttime.h"

/* Allgemeiner Konstruktor */
tfixeddepositaccount::tfixeddepositaccount(tcustomer *customer, tbank *bank, string accountNumber, string pin, tmoney dispo, double zinsen): 
	tcurrentaccount(customer, bank, accountNumber, pin, dispo, 4), 
	tsavingsaccount(customer, bank, accountNumber, pin, zinsen, 4),
	taccount(customer, bank, accountNumber, pin, false, 4)
{
  customer->setAccount(this);
  bank->setBankaccount(this);
}

/* Destruktor */
tfixeddepositaccount::~tfixeddepositaccount()
{
  cout << "tsavingsaccount:          Tagesgeldkonto      (KtoNr. " << taccount::get_accountNumber() << ") wird vernichtet!" << endl;
}

void tfixeddepositaccount::printAccountStatement()
{
  taccount::printAccountStatement();
  cout << "max. Dispo:            "; tcurrentaccount::get_dispo().print(); cout << endl;
  cout << "Zinssatz:                   " << tsavingsaccount::get_zinsen() << " %" << endl;
}

tmoney tfixeddepositaccount::get_possibleMoney()
{
  tmoney dummy;
  
  dummy.add(this->get_dispo());
  dummy.add(taccount::get_money());
  return dummy;
}