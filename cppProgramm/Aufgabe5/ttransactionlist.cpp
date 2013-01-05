#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "ttransactionlist.h"
#include "tdate.h"
#include "ttime.h"

/* Allgemeiner Konstruktor */
ttransactionlist::ttransactionlist(char *dateiName)
{
  this -> transactionDate = tdate();
  this -> transactionTime = ttime();
  ifstream datei;
  string zeile;
  
  datei.open(dateiName, ios_base::in);
  if(!datei)
  {
    cout << "\n Datei konnte nicht geöffnet werden" << endl;
  }
  else
  {
    while(!(datei.eof()))
    {
      getline(datei, zeile, '\n');
      if(!zeile.find("<Transactionlist>"))
      {
        cout << zeile << endl;
      }
      else
      {
      cout << "fehler" << endl;
      }
    }
    datei.close();
  }
}

ttransactionlist::~ttransactionlist()
{
 
}

