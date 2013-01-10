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
/* account anlegen
   accountType auf 1 setzen (Standardaccount)
   account bei dem zugehörigen customer registrieren
   account bei der zugehörigen bank registrieren*/
taccount::taccount(tcustomer *customer, tbank *bank, string accountNumber, string pin, int accountType)
{
  set(customer, bank, accountNumber, pin);
  this -> accountType = 1;
  customer->setAccount(this);
  bank->setBankaccount(this);
}

/* Konstruktor für Ableitung*/
/* Konstruktor hat eine Variable mehr wie der Allgemeine Konstruktor
   so kann unterschieden werden welcher Konstruktor genutzt werden soll*/
/* account anlegen
   accountType auf übergebenen Wert setzen*/
taccount::taccount(tcustomer *customer, tbank *bank, string accountNumber, string pin, bool OK, int accountType)
{
  set(customer, bank, accountNumber, pin);
  this -> accountType = accountType;
}

/* Destruktor */
/* Wenn ein Objekt vom Typ taccount zerstoert wird, wird bei dem
   dazugehoerigen customer die Anzahl der Accounts um 1 verringert */
/* anzahl accounts bei customer reduziert
   anzahl accounts bei bank reduziert
   löschen aller eingetragenen bookings in diesen Account*/
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

/* set methode .. wird vom Allgemeinen Konstruktor angegrufen*/
void taccount::set(tcustomer *customer, tbank *bank, string accountNumber, string pin)
{
  this -> customer = customer;
  this -> bank = bank;
  this -> accountNumber = accountNumber;
  this -> pin = pin;
  this -> amountBookings = 0;
  tmoney amount;
}

/* print methode .. gibt Grundangaben aus */
void taccount::print()
{
//  customer->print(); .... raus wegen überladen <<
  cout << customer;
  cout << endl;
// vielleicht noch Ausgabe des Banknamen + Bankleitzahl bei dem das Konto ist  
  cout << "Kontonummer      : " << accountNumber << endl;
  cout << "Anzahl Buchungen : " << amountBookings << endl;
  cout << "Kontostand       : " << amount;
}

/* verarbeitet ein neues booking für den account */
/* ruft den Kopierkonstruktor auf um eine neues booking im account zu erstellen
   negiert den Wert
   addiert den Wert zum aktuellen Kontostand
   erhöht die Anzahl der booking um 1*/
void taccount::setAccountBooking(tbooking *booking)
{ 
  this -> bookings[amountBookings]  = new tbooking(booking);
  (this ->bookings[amountBookings])->set_amount();
  amount.add((this->bookings[amountBookings])->get_amount());
  amountBookings++;
}

/* verarbeitet ein neues booking für den contraaccount */
/* ruft den Kopierkonstruktor auf um eine neues booking im account zu erstellen
   addiert den Wert zum aktuellen Kontostand
   erhöht die Anzahl der booking um 1*/
void taccount::setContraBooking(tbooking *booking)
{
  this -> bookings[amountBookings]  = new tbooking(booking);
  amount.add((this->bookings[amountBookings])->get_amount());
  amountBookings++;
}

/* Grund-Ausgabemethode für den Kontoauszug*/
void taccount::printAccountStatement()
{
  bool print = false;

  /* Tabellenkopf */
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
  
  /* Geht die einzelnen bookings durch */
  for(int i = 0; i < amountBookings; i++)
  {   
    /* überprüft ob der aktuelle account der contraaccount ist */
    if(accountNumber.compare(((*bookings[i]).get_contraAccount())->get_accountNumber()) != 0)
    {
	  /* geht alle bookings durch, wenn printed = False ist wird er ausgegeben */
	  if(!(*bookings[i]).get_printed())
      {
		print = true;
        (*bookings[i]).set_printed();
        (*bookings[i]).get_date().print(); 
        cout << setfill(' ');
        cout << " |" << setw(11) << right; (*bookings[i]).get_amount().print(); cout << " | " << left << setw(30) << (*bookings[i]).get_contraAccount()->get_customer()->get_name() << "| " << (*bookings[i]).get_text() << endl;
      }
    }
    else
    { 
      /* geht alle bookings durch, wenn printed = False ist wird er ausgegeben */
      if(!(*bookings[i]).get_printed())
      {
		print = true;
        (*bookings[i]).set_printed();
        (*bookings[i]).get_date().print(); 
        cout << setfill(' ');
        cout << " |" << setw(11) << right; (*bookings[i]).get_amount().print(); cout << " | " << left << setw(30) << (*bookings[i]).get_account()->get_customer()->get_name() << "| " << (*bookings[i]).get_text() << endl;
      }
    }
  }
  /* wenn kein booking ausgegeben wurde ist printed noch false */
  if(!print)
  {
    cout << "Keine neuen Buchungen vorhanden" << endl;
  } 
  /* Ausgabe Tabellenfuß */
  cout << setfill('-');
  cout << right << setw(12) << "|"
       << setw(17) << "|"
       << setw(32) << "|"
       << setw(14) << "-" << endl;
  cout << setfill(' ');
  cout << "aktueller Kontostand: " << setw(10) << right << amount << endl;
}