#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tbank.h"
#include "tcustomer.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
tbank::tbank(string bankName, string bankleitzahl)
{
  set(bankName, bankleitzahl);
}

/* Destruktor */
tbank::~tbank()
{

}

void tbank::set(string bankName, string bankleitzahl)
{
  this -> bankName = bankName;
  this -> bankleitzahl = bankleitzahl;
  this -> amountBankaccounts = 0;
}

void tbank::print()
{
  cout << bankName << endl;
  cout << "Bankleitzahl : " << bankleitzahl << endl;
  cout << "Anzahl Konten: " << amountBankaccounts << endl;
  cout << "Kontenliste  : " << endl;
  
  cout << setfill(' ');
  cout << left << setw(11) << "KontoNr." << "|" 
       << left << setw(32) << " Kundenname" << "|" 
       << left << setw(16) << " Anz. Buchungen" << "|" 
       << left << setw(15) << " Kontostand" << endl;
  cout << setfill('-');
  cout << right << setw(12) << "|"
       << right << setw(33) << "|"
       << right << setw(17) << "|"
       << right << setw(16) << "";
  cout << setfill(' ');
  for (int i = 0; i < amountBankaccounts; i++)
  {
    cout << endl; 
    cout << right << setw(10) << (*accounts[i]).get_accountNumber()
         << " | " << left << setw(30) << (*accounts[i]).get_customer()->get_name()
         << " | " << right << setw(14) << (*accounts[i]).get_amountBookings()
         << " | "; (*accounts[i]).get_money().print(); cout << flush;
  }
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