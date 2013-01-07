#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "ttransactionlist.h"
#include "ttransaction.h"
#include "tdate.h"
#include "ttime.h"

/* Allgemeiner Konstruktor */
ttransactionlist::ttransactionlist(char *dateiName)
{
  this -> transactionDate = tdate();
  this -> transactionTime = ttime();
  this -> TransactionsCount = 0;
  ifstream datei;
  string zeile;

  datei.open(dateiName, ios_base::in);
  if(!datei)
  {
    cout << "\n Datei konnte nicht geoeffnet werden" << endl;
  }
  else
  {
    getline(datei, zeile, '\n');
    if(zeile.compare(0, 17, "<Transactionlist>") == 0)
    {
      getline(datei, zeile, '\n');
      while(!(datei.eof()))
      {
        if(zeile.compare(2, 13, "<Transaction>") == 0)
        {
          trans.resize(TransactionsCount);
          TransactionsCount++;
          trans.push_back(*(new ttransaction(datei)));
          getline(datei, zeile, '\n');
        }
        else if(zeile.compare(0, 18, "</Transactionlist>") == 0)
        {
          break;
        }
        else
        {
          cout << "error: Fehler im Dateiformat [ttransactionlist 1]" << zeile << endl;
          break;
        }
      }
    }
    if(zeile.compare(0, 18, "</Transactionlist>") == 0)
    {
    }
    else
    {
      cout << "error: Fehler im Dateiformat [ttransactionlist 2]" << zeile << endl;
    }
    datei.close();
  }
}

ttransactionlist::~ttransactionlist()
{
 
}

ostream &operator<< (ostream &ostr, ttransactionlist &transactionL)
{
  for (unsigned i = 0; i < transactionL.TransactionsCount; i++)
  {
    ostr << "Transaction Nummer " << i+1 << ":" << endl;
    ostr << (transactionL.trans.at(i)) << endl;
  }
  return ostr;
}