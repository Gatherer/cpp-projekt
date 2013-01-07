#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tcustomer.h"

/* Allgemeiner Konstruktor */
/* Bei der Erstellung eines Objektes vom Typ cutomer wird
   amountAccounts mit 0 initialisiert */
/* Initalisierung von *account mit NULL nur damit bei der Ausgabe definierte
   Werte sichtbar sind. */
tcustomer::tcustomer(string name, tdate birthday, string street, string housenumber, string zipcode, string city)
{
  tcustomer::set(name, birthday, street, housenumber, zipcode, city);
  this -> amountAccounts = 0;
}

void tcustomer::set(string name, tdate birthday, string street, string housenumber, string zipcode, string city)
{
  this -> name = name;
  this -> birthday = birthday;
  this -> street = street;
  this -> housenumber = housenumber;
  this -> zipcode = zipcode;
  this -> city = city; 
}

ostream &operator<< (ostream &ostr, tcustomer &kunde)
{
  int i;
  
  ostr << kunde.name << endl;
  ostr << kunde.street << " " << kunde.housenumber << endl;
  ostr << kunde.zipcode << " " << kunde.city << endl;
  ostr << "geboren am: "; kunde.birthday.print(); 
  ostr << endl;
  ostr << "Konten:" << flush;
  ostr << setfill(' ');
  for (i = 0; i < kunde.amountAccounts; i++)
  {
    tmoney dummyMoney = (*kunde.accounts[i]).get_money();
    ostr << endl; 
    ostr << "- Kontonummer: " << setw(11) << right << (*kunde.accounts[i]).get_accountNumber() 
         << " (Kontostand:"   << dummyMoney << ")" << flush;
  }
  return ostr;
}

/* wird von tcustomer Dekonstruktor aufgerufen */
void tcustomer::deleteAmountAccounts()
{
	amountAccounts--;
}

/* */
void tcustomer::setAccount(taccount *account)
{
  this -> accounts[amountAccounts]  = account;
  amountAccounts++;
}