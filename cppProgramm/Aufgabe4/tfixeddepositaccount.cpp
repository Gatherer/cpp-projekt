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
tfixeddepositaccount::tfixeddepositaccount(tcustomer *customer, tbank *bank, string accountNumber, string pin, tmoney dispo,
  double zinsen): tcurrentaccount(customer, bank, accountNumber, pin, dispo, false, 4), tsavingsaccount(customer, bank, accountNumber, pin, zinsen, false, 4)
{
  customer->setAccount(this);
  bank->setBankaccount(this);
}

/* Destruktor */
tfixeddepositaccount::~tfixeddepositaccount()
{
  cout << "tsavingsaccount:          Sparkonto           (KtoNr. " << taccount::get_accountNumber() << ") wird vernichtet!" << endl;
}

void tfixeddepositaccount::printAccountStatement()
{
  //taccount::printAccountStatement();
 // cout << "Zinssatz: " << zinsen << " %" << endl;
}

tmoney tfixeddepositaccount::get_possibleMoney()
{
  tmoney dummy;
  
  dummy.add(this->get_dispo());
  dummy.add(taccount::get_money());
  return dummy;
}