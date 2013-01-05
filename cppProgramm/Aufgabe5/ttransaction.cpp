#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "ttransaction.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
ttransaction::ttransaction(istream &istr)
{
  bookingAmount = tmoney();

  string zeile;
  int stringStart;
  int stringStop;

  getline(istr, zeile, '\n');
  while(!(istr.eof()))
  {
    if(zeile.compare(4, 11, "<AccountNr>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      accountNumber = zeile.substr(stringStart, stringStop-stringStart);
      cout << zeile << endl;
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 5, "<BLZ>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      bankleitzahl = zeile.substr(stringStart, stringStop-stringStart);
      cout << zeile << endl;
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 17, "<ContraAccountNr>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      contraAccountNumber = zeile.substr(stringStart, stringStop-stringStart);
      cout << zeile << endl;
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 11, "<ContraBLZ>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      contraBankleitzahl = zeile.substr(stringStart, stringStop-stringStart);
      cout << zeile << endl;
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 6, "<Text>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      buchungstext = zeile.substr(stringStart, stringStop-stringStart);
      cout << zeile << endl;
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 7, "<Money>") == 0)
    {
      cout << zeile << endl;
      tmoney *t1 = new tmoney(istr);
      getline(istr, zeile, '\n');
    }
    else
    {
      cout << "error: Fehler im Dateiformat " << zeile << endl;
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