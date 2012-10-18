#ifndef TMONEY_H_
#define TMONEY_H_

#include <string>

class tmoney 
{
  public:
    tmoney();
    tmoney(double amount, std::string currency="Euro");
    
    void print();
    void set(double amount, std::string currency);
    double get_amount() { return amount; }
    string get_currency() { return currency; }

  private:
    double amount;
    std::string currency;
};

#endif /* TMONEY_H_ */