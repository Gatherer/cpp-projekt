#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "taccount.h"
#include "tmoney.h"
#include "tbank.h"
#include "tdate.h"
#include "ttime.h"

/* Allgemeiner Konstruktor */
/* Wenn ein Objekt vom Typ taccount angelegt wird, wird bei dem
   dazugehoerigen customer die Anzahl der Accounts um 1 erhoeht */
taccount::taccount(tcustomer *customer, tbank *bank, string accountNumber, string pin)
{
  set(customer, bank, accountNumber, pin);
  customer->setAccount(this);
  bank->setBankaccount(this);
}

taccount::taccount(tcustomer *customer, tbank *bank, string accountNumber, string pin, bool OK)
{
  set(customer, bank, accountNumber, pin);
}

/* Destruktor */
/* Wenn ein Objekt vom Typ taccount zerstoert wird, wird bei dem
   dazugehoerigen customer die Anzahl der Accounts um 1 verringert */
taccount::~taccount()
{
  customer->deleteAmountAccounts();
  bank->deleteBankAccount();
  cout << "taccount:                 Konto               (KtoNr. " << accountNumber << ") wird vernichtet!" << endl;
  int k = amountBookings;
  for (int i = 0; i < k; i++)
  {
    delete bookings[i];
  }
}

void taccount::set(tcustomer *customer, tbank *bank, string accountNumber, string pin)
{
  this -> customer = customer;
  this -> bank = bank;
  this -> accountNumber = accountNumber;
  this -> pin = pin;
  this -> amountBookings = 0;
  tmoney amount;
}

void taccount::print()
{
  customer->print();
  cout << endl;
// vielleicht noch Ausgabe des Banknamen + Bankleitzahl bei dem das Konto ist  
  cout << "Kontonummer      : " << accountNumber << endl;
  cout << "Anzahl Buchungen : " << amountBookings << endl;
  cout << "Kontostand       : " << flush; amount.print();
}

void taccount::setAccountBooking(tbooking *booking)
{ 
  this -> bookings[amountBookings]  = new tbooking(booking);
  (this ->bookings[amountBookings])->set_amount();
  amount.add((this->bookings[amountBookings])->get_amount());
  amountBookings++;
}

void taccount::setContraBooking(tbooking *booking)
{
  this -> bookings[amountBookings]  = new tbooking(booking);
  amount.add((this->bookings[amountBookings])->get_amount());
  amountBookings++;
}

void taccount::printAccountStatement()
{
  bool print = false;
  cout << "Kontoauszug vom "; tdate().print(); cout << "; ";  ttime().print(); cout << endl;
  cout << setfill(' ');
  cout << "Kontonummer:" << right << setw(12) << accountNumber << "; BLZ: " << bank->get_bankleitzahl() << endl;
  cout << "Kontoinhaber: " << customer->get_name() << endl;
  cout << setfill(' ');
  cout << left << setw(11) << "Datum" << "|"
       << right << setw(16) << "Betrag " << "|"
       << left << setw(32) << " Absender / Empfänger" << "|"
       << setw(14) << " Buchungstext" << endl;
  cout << setfill('-');
  cout << right << setw(12) << "|"
       << setw(17) << "|"
       << setw(32) << "|"
       << setw(14) << "-" << endl;
  for(int i = 0; i < amountBookings; i++)
  {    
    if(accountNumber.compare(((*bookings[i]).get_contraAccount())->get_accountNumber()) != 0)
    {
      if(!(*bookings[i]).get_printed())
      {
        print = true;
        (*bookings[i]).set_printed();
        (*bookings[i]).get_date().print(); 
        cout << setfill(' ');
        cout << " |"; (*bookings[i]).get_amount().print(); cout << " | " << left << setw(30) << (*bookings[i]).get_contraAccount()->get_customer()->get_name() << "| " << (*bookings[i]).get_text() << endl;
      }
    }
    else
    {  
      if(!(*bookings[i]).get_printed())
      {
        print = true;
        (*bookings[i]).set_printed();
        //(*bookings[i]).set_printedcontra();
        (*bookings[i]).get_date().print(); 
        cout << setfill(' ');
        cout << " |"; (*bookings[i]).get_amount().print(); cout << " | " << left << setw(30) << (*bookings[i]).get_account()->get_customer()->get_name() << "| " << (*bookings[i]).get_text() << endl;
      }
    }
  }
  if(!print)
  {
    cout << "Keine neuen Buchungen vorhanden" << endl;
  } 
  cout << setfill('-');
  cout << right << setw(12) << "|"
       << setw(17) << "|"
       << setw(32) << "|"
       << setw(14) << "-" << endl;
  cout << setfill(' ');
  cout << "aktueller Kontostand: "; amount.print(); cout << endl;
}