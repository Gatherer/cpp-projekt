#ifndef TTRANSACTIONLIST_H_
#define TTRANSACTIONLIST_H_

#include <string>
#include <vector>
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
    
  private:
    tdate transactionDate;
    ttime transactionTime;
    std::vector<ttransaction> trans;
    
//    friend ostream &operator<< (ostream &ostr, ttransaction &transa);
    
//    friend class taccount;
};

#endif /* TTRANSACTIONLIST_H_ */