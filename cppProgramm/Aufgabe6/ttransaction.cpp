#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "ttransaction.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
ttransaction::ttransaction(istream &istr)
{
  string zeile;
  int stringStart;
  int stringStop;

  getline(istr, zeile, '\n');
  while(!(istr.eof()))
  {
    // accountNumber, contraAccountNumber, bankleitzahl und contraBankleitzahl sind
    // getauscht da wir eine andere Reihenfolge haben.
    if(zeile.compare(4, 11, "<AccountNr>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      contraAccountNumber = zeile.substr(stringStart, stringStop-stringStart);
//      accountNumber = zeile.substr(stringStart, stringStop-stringStart);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 5, "<BLZ>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      contraBankleitzahl = zeile.substr(stringStart, stringStop-stringStart);
//      bankleitzahl = zeile.substr(stringStart, stringStop-stringStart);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 17, "<ContraAccountNr>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      accountNumber = zeile.substr(stringStart, stringStop-stringStart);
//      contraAccountNumber = zeile.substr(stringStart, stringStop-stringStart);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 11, "<ContraBLZ>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      bankleitzahl = zeile.substr(stringStart, stringStop-stringStart);
//      contraBankleitzahl = zeile.substr(stringStart, stringStop-stringStart);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 6, "<Text>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      buchungstext = zeile.substr(stringStart, stringStop-stringStart);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 7, "<Money>") == 0)
    {
      bookingAmount = tmoney(istr);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(2, 14, "</Transaction>") == 0)
    {
      break;
    }
    else
    {
      cout << "error: Fehler im Dateiformat [ttransaction]" << zeile << endl;
      break;
    }
  }
}

ttransaction::ttransaction()
{
}

ttransaction::~ttransaction()
{
 
}

ostream &operator<< (ostream &ostr, ttransaction &transaction)
{
  ostr << "AccountNummer =         " << transaction.accountNumber       << endl;
  ostr << "BLZ =                   " << transaction.bankleitzahl        << endl;
  ostr << "ContraAccountNummer =   " << transaction.contraAccountNumber << endl;
  ostr << "ContraBLZ =             " << transaction.contraBankleitzahl  << endl; 
  ostr << "Amount =                " << transaction.bookingAmount       << endl;
  ostr << "Text =                  " << transaction.buchungstext        << endl;
  return ostr;
}