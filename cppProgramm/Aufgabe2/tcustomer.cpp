#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tcustomer.h"

tcustomer::tcustomer(string name, string surname, tdate birthday, string street, string housenumber, string zipcode, string city)
{
  tcustomer::set(name, surname, birthday, street, housenumber, zipcode, city);
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

void tcustomer::print()
{
  cout << name << " " << surname << endl;
  cout << street << " " << housenumber << endl;
  cout << zipcode << " " << city << endl;
  cout << "geboren am: "; birthday.print(); cout << endl;
  cout << "Konten:" << cout;
//  cout << "- Kontonummer: "; *A_tcustomer.account[Zählvariable] Ausgabe Kontonummern
}

int tcustomer::amountAccounts = 0;