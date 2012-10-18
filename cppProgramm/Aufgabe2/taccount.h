#ifndef TACCOUNT_H_
#define TACCOUNT_H_

#include <string>

#include "tmoney.h"
#include "tcustomer.h"

class tcustomer;
class tmoney;

class taccount
{
  public:
    taccount(tcustomer *customer, std::string accountNumber, std::string pin);
    
    void print();
    void set(tcustomer *customer, std::string accountNumber, std::string pin);
    
    string get_accountNumber() {return accountNumber; }
    string get_pin() {return pin; }
    int get_amountBookings() {return amountBookings; }

  private:
    tcustomer *customer;
    std::string accountNumber;
    std::string pin;
    int amountBookings;
    tmoney amount;
};

#endif /* TACCOUNT_H_ */