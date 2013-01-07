#ifndef TTRANSACTION_H_
#define TTRANSACTION_H_

#include <string>
#include "tmoney.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class tmoney;

/* Klasse taccount */
class ttransaction
{
  public:
    /* Konstruktoren */
    ttransaction();
    ttransaction(istream &istr);
    
    /* Destruktor */
    virtual ~ttransaction();

    /* set() und get() Methoden */
    string get_BLZ() {return bankleitzahl;}
    string get_ContraBLZ() {return contraBankleitzahl;}
    string get_AccountNr() {return accountNumber;}
    string get_ContraAccountNr() {return contraAccountNumber;}
    string get_Text() {return buchungstext;}
    double get_amount2() {return bookingAmount.get_amount();}

  private:
    std::string accountNumber;
    std::string contraAccountNumber;
    std::string bankleitzahl;
    std::string contraBankleitzahl;
    std::string buchungstext;
    tmoney bookingAmount;

    friend ostream &operator<< (ostream &ostr, ttransaction &transaction);
};

#endif /* TTRANSACTION_H_ */