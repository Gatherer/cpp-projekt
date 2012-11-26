#ifndef TCURRENTACCOUNT_H_
#define TCURRENTACCOUNT_H_

#include "tmoney.h"
#include "taccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;
class taccount;

/* Klasse taccount */
class tcurrentaccount: virtual public taccount
{
  public:
    /* Konstruktoren */
    tcurrentaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      tmoney dispo);
	tcurrentaccount(tcustomer *customer, tbank *bank, std::string accountNumber, std::string pin, 
      tmoney dispo, bool ZK, int accountType);
    
  /* Destruktor */
  virtual ~tcurrentaccount();

  /* set() und get() Methoden */
  void set_dispo(double amount);
  virtual tmoney get_possibleMoney();
  tmoney get_dispo() { return dispo; }

  /* print Methoden */
  void printAccountStatement();
  
  private:
    tmoney dispo;
	bool ZK;
};
#endif /* TCURRENTACCOUNT_H_ */