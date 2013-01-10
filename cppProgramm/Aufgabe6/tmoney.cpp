#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

#include "tmoney.h"
#include "tfixeddepositaccount.h"

/* Allgemeiner Konstruktor */
tmoney::tmoney(double amount, string currency)
{
  set(amount, currency);
}

tmoney::tmoney(istream &istr)
{
  string zeile;
  string amount_new;
  int stringStart;
  int stringStop;

  getline(istr, zeile, '\n');
  while(!(istr.eof()))
  {
    if(zeile.compare(6, 8, "<Amount>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      amount_new = (zeile.substr(stringStart, stringStop-stringStart));
      amount = atof(amount_new.c_str());
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(6, 10, "<Currency>") == 0)
    {
      stringStart = (zeile.find_first_of('>')+1);
      stringStop  = (zeile.find_last_of('<'));
      currency = zeile.substr(stringStart, stringStop-stringStart);
      getline(istr, zeile, '\n');
    }
    else if(zeile.compare(4, 8, "</Money>") == 0)
    {
      break;
    }
    else
    {
      cout << "error: Fehler im Dateiformat [tmoney]" << zeile << endl;
      break;
    }
  }
}

/* Standardkonstruktor */
tmoney::tmoney()
{
  set(0.0, "EUR");
}

void tmoney::set(double amount, string currency)
{
  this -> amount = amount;
  this -> currency = currency;
}

void tmoney::set_amount(double amount)
{
  this -> amount = amount;
}

ostream &operator<< (ostream &ostr, tmoney &money)
{
  ostr << right << fixed << setprecision(2) <<  money.amount << " " << money.currency << flush;
  return ostr;
}

void tmoney::print()
{
  cout << right << fixed << setprecision(2) <<  amount << " " << currency << flush;
}

void tmoney::sub(tmoney amountChange)
{
  amount = amount - amountChange.amount;
}

void tmoney::add(tmoney amountChange)
{
  amount = amount + amountChange.amount;
}