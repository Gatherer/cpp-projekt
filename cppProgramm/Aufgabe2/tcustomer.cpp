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
  for (int i = 0; i<MAXACCOUNTS; i++)
  {
	accounts[i] = NULL;
  }
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
  cout << name << " " << surname << endl;
  cout << street << " " << housenumber << endl;
  cout << zipcode << " " << city << endl;
  cout << "geboren am: "; birthday.print(); cout << endl;
  cout << "Konten:" << endl;
  cout << "- Kontonummer: " << accounts[0];
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