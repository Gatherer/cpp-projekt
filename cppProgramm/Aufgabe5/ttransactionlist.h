#ifndef TTRANSACTIONLIST_H_
#define TTRANSACTIONLIST_H_

#include <string>
#include <vector>

#include "tbank.h"
#include "tdate.h"
#include "ttime.h"
#include "ttransaction.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tdate;
class ttime;
class ttransaction;

/* Klasse ttransactionlist */
class ttransactionlist
{
  public:
    /* Konstruktoren */
    ttransactionlist(char *dateiName);
    
    /* Destruktor */
    virtual ~ttransactionlist();

    /* set() und get() Methoden */
    unsigned get_TransactionsCount() {return TransactionsCount;}
    tdate get_date() {return transactionDate;}
    ttime get_time() {return transactionTime;}
    
    ttransaction operator[] (unsigned i)
    {
      if((i >= 0) && (i < TransactionsCount))
      { return trans.at(i); }
      else
      { return trans.at(i); }
    }

  private:
    tdate transactionDate;
    ttime transactionTime;
    vector<ttransaction> trans;
    unsigned TransactionsCount;
    
    friend ostream &operator<< (ostream &ostr, ttransactionlist &transactionL);
};

#endif /* TTRANSACTIONLIST_H_ */