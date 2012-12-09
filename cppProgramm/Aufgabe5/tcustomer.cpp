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

/* Ausgabe der Kontonummern fehlt noch */
void tcustomer::print()
{ 
  int i;
  
  cout << name << endl;
  cout << street << " " << housenumber << endl;
  cout << zipcode << " " << city << endl;
  cout << "geboren am: "; birthday.print(); cout << endl;
  cout << "Konten:" << flush;
  cout << setfill(' ');
  for (i = 0; i < amountAccounts; i++)
  {
    tmoney dummyMoney = (*accounts[i]).get_money();
    cout << endl; 
    cout << "- Kontonummer: " << setw(11) << right << (*accounts[i]).get_accountNumber() 
         << " (Kontostand:"; dummyMoney.print(); cout << ")" <<flush;
  }
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