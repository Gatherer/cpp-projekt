#ifndef TMONEY_H_
#define TMONEY_H_

#include <string>

/* Klasse tmoney */
class tmoney 
{
  public:
    /* Konstruktoren */
    tmoney();
    tmoney(double amount, std::string currency="EUR");
    tmoney(istream &istr);
    
    /* Dekonstruktor */

    /* set() und get() Methoden */
    void set(double amount, std::string currency);
    void set_amount(double amount);
    
    double get_amount() { return amount; }
    string get_currency() { return currency; }

    void add(tmoney amountChange);
    void sub(tmoney amountChange);
    
    void print();
  
  private:
    double amount;
    std::string currency;

    friend ostream &operator<< (ostream &ostr, tmoney &money);
};

#endif /* TMONEY_H_ */