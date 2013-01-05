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

  private:
    std::string accountNumber;
    std::string contraAccountNumber;
    std::string bankleitzahl;
    std::string contraBankleitzahl;
    std::string buchungstext;
    tmoney bookingAmount;
};

#endif /* TTRANSACTION_H_ */