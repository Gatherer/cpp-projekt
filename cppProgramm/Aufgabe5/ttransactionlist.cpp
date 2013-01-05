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
    while(!(datei.eof()))
    {
      if(zeile.compare(0, 17, "<Transactionlist>") == 0)
      {
        cout << zeile << endl;
        getline(datei, zeile, '\n');
        if(zeile.compare(2, 13, "<Transaction>") == 0)
        {
          cout << zeile << endl;
          trans.resize(1);
          ttransaction *t1 = new ttransaction(datei);
          getline(datei, zeile, '\n');
        }
        else
        {
          cout << "error: Fehler im Dateiformat " << zeile << endl;
          break;
        }
      }
      else
      {
      cout << "error: Fehler im Dateiformat " << zeile << endl;
      break;
      }
    }
    datei.close();
  }
}

ttransactionlist::~ttransactionlist()
{
 
}

