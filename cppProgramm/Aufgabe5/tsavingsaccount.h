#ifndef TSAVINGSACCOUNT_H_
#define TSAVINGSACCOUNT_H_

#include "tmoney.h"
#include "taccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;
class taccount;

/* Klasse taccount */
class tsavingsaccount: virtual public taccount
{
  public:
    /* Konstruktoren */
    tsavingsaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      double zinsen);
	tsavingsaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      double zinsen, int accountType);
    
  /* Destruktor */
  virtual ~tsavingsaccount();

  /* set() und get() Methoden */
  void set_zinsen(double zinsen);
  double get_zinsen() { return zinsen; }
  virtual tmoney get_possibleMoney();
  
  /* print Methoden */
  void printAccountStatement();
  
  private:
    double zinsen;
};
#endif /* TSAVINGSACCOUNT_H_ */