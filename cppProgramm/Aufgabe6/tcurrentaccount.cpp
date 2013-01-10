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
  tmoney dispo): taccount(customer, bank, accountNumber, pin, false, 2)
{
  this -> dispo = dispo;
  customer->setAccount(this);
  bank->setBankaccount(this);
}

/* Konstruktor wenn tcurrentaccount die OK von tfixeddepositaccount ist */
tcurrentaccount::tcurrentaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      tmoney dispo, int accountType): taccount(customer, bank, accountNumber, pin, false, accountType)
{
  this -> dispo = dispo;
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
  cout << "max. Dispo: " << setw(20) << right << dispo << endl;
}

tmoney tcurrentaccount::get_possibleMoney()
{
  tmoney dummy;
  
  dummy.add(dispo);
  dummy.add(taccount::get_money());
  return dummy;
}