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
tcustomer::tcustomer(string name, string surname, tdate birthday, string street, string housenumber, string zipcode, string city)
{
  tcustomer::set(name, surname, birthday, street, housenumber, zipcode, city);
  this -> amountAccounts = 0;
}

void tcustomer::set(string name, string surname, tdate birthday, string street, string housenumber, string zipcode, string city)
{
  this -> name = name;
  this -> surname = surname;
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
  
  cout << name << " " << surname << endl;
  cout << street << " " << housenumber << endl;
  cout << zipcode << " " << city << endl;
  cout << "geboren am: "; birthday.print(); cout << endl;
  cout << "Konten:" ;
  for (i = 0; i < amountAccounts; i++)
  {
    cout << endl; 
    cout << "- Kontonummer: " << (*accounts[i]).get_accountNumber();
  }
}

/* wird von tcustomer Konstruktor aufgerufen */
void tcustomer::addAmountAccounts()
{
	amountAccounts++;
}

/* wird von tcustomer Dekonstruktor aufgerufen */
void tcustomer::deleteAmountAccounts()
{
	amountAccounts--;
}

/* */
void tcustomer::setAccount(taccount *account)
{
  this -> accounts[amountAccounts-1]  = account;
}