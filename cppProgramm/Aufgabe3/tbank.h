#ifndef TBANK_H_
#define TBANK_H_

#define MAXBANKACCOUNTS 100

#include <string>

#include "taccount.h"

/* Klassen fuer Vorwertsdeklaration bekannt machen */
class taccount;

/* Klasse taccount */
class tbank
{
  public:
    /* Konstruktoren */
    tbank(std::string bankName, std::string bankleitzahl);
    
    /* Destruktor */
    virtual ~tbank();

    /* set() und get() Methoden */
    void set(std::string bankName, std::string bankleitzahl);

    string get_bankName() { return bankName; }
    string get_bankleitzahl() { return bankleitzahl; }
    int get_amountBankaccounts() { return amountBankaccounts; }
//  get Methode fuer accounts vielleicht noch
    
    /* print Methoden */
    void print();

  private:
    taccount *accounts[MAXBANKACCOUNTS];
    std::string bankName;
    std::string bankleitzahl;
    int amountBankaccounts;
    
    friend class taccount;
    
    void deleteBankAccount();
    void setBankaccount(taccount *account);
};
#endif /* TBANK_H_ */