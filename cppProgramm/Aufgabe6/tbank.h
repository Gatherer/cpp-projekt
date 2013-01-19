#ifndef TBANK_H_
#define TBANK_H_

#include <string>

#include "taccount.h"
#include "tliste.h"

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
    int get_amountBankaccounts() { return accounts.size(); }
    taccount *get_Account(int i) {return accounts[i]; }
    // nervig das hier gemacht werden muss
    taccount *get_Account2(string accNumber)
    {
      int k = accounts.size();
      int j = 0;
      for(int i = 0; i < k; i++)
      {
        if(accNumber == accounts[i]->get_accountNumber())
        {
          j = i;
          break;
        }
      }
      return accounts[j];
    }
    
    /* print Methoden */
    void print();

  private:
    Liste <taccount*> accounts;
    std::string bankName;
    std::string bankleitzahl;
    
    friend ostream &operator<< (ostream &ostr, tbank &bank);
    
    friend class taccount;
    friend class tcurrentaccount;
    friend class tsavingsaccount;
    friend class tfixeddepositaccount;
    
    void deleteBankAccount();
    void setBankaccount(taccount *account);
};
#endif /* TBANK_H_ */