#ifndef TFIXEDDEPOSITACCOUNT_H_
#define TFIXEDDEPOSITACCOUNT_H_

#include "tmoney.h"
#include "taccount.h"
#include "tcurrentaccount.h"
#include "tsavingsaccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;
class tcurrentaccount;
class tsavingsaccount;

/* Klasse tfixeddepositaccount */
class tfixeddepositaccount: public tcurrentaccount, public tsavingsaccount
{
  public:
    /* Konstruktoren */
     tfixeddepositaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      tmoney dispo, double zinsen);
    
  /* Destruktor */
  virtual ~tfixeddepositaccount();

  /* set() und get() Methoden */
  tmoney get_possibleMoney();


  /* print Methoden */
  void printAccountStatement();
  
  private:

};
#endif /* TFIXEDDEPOSITACCOUNT_H_ */