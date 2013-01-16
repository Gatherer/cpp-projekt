#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tbank.h"
#include "tcustomer.h"
#include "tmoney.h"
#include "tliste.h"

/* Allgemeiner Konstruktor */
tbank::tbank(string bankName, string bankleitzahl)
{
  set(bankName, bankleitzahl);
}

/* Destruktor */
tbank::~tbank()
{
  int k = amountBankaccounts;
  for (int i = 0; i < k; i++)
  {
    delete accounts[i];
  }
}

void tbank::set(string bankName, string bankleitzahl)
{
  this -> bankName = bankName;
  this -> bankleitzahl = bankleitzahl;
  this -> amountBankaccounts = 0;
}

ostream &operator<< (ostream &ostr, tbank &bank)
{
  ostr << bank.bankName << endl;
  ostr << "Bankleitzahl : " << bank.bankleitzahl << endl;
  ostr << "Anzahl Konten: " << bank.amountBankaccounts << endl;
  ostr << "Kontenliste  : " << endl;
  
  ostr << setfill(' ');
  ostr << left << setw(11) << "KontoNr." << "|" 
       << left << setw(32) << " Kundenname" << "|" 
       << left << setw(16) << " Anz. Buchungen" << "|" 
       << left << setw(15) << " Kontostand" << endl;
  ostr << setfill('-');
  ostr << right << setw(12) << "|"
       << right << setw(33) << "|"
       << right << setw(17) << "|"
       << right << setw(16) << "";
  ostr << setfill(' ');
  for (int i = 0; i < bank.amountBankaccounts; i++)
  {
    ostr << endl; 
    ostr << right << setw(10) << (*bank.accounts[i]).get_accountNumber()
         << " | " << left << setw(30) << (*bank.accounts[i]).get_customer()->get_name()
         << " | " << right << setw(14) << (*bank.accounts[i]).get_amountBookings()
         << " | " << setw(10) << right;(*bank.accounts[i]).get_money().print();
    ostr << flush;
  }
  return ostr;
}

/* wird von taccount Dekonstruktor aufgerufen */
void tbank::deleteBankAccount()
{
  amountBankaccounts--;
}

/* */
void tbank::setBankaccount(taccount *account)
{
  this -> accounts[amountBankaccounts]  = account;
  amountBankaccounts++;
}
