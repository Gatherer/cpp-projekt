#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "tbooking.h"
#include "taccount.h"
#include "tdate.h"
#include "ttime.h"
#include "tmoney.h"

/* Allgemeiner Konstruktor */
tbooking::tbooking(tmoney amount, taccount *account, taccount *contraaccount, tdate date, ttime time, string text)
{
  set(amount, account, contraaccount, date, time, text);
}

tbooking::tbooking(tbooking *booking)
{
  this -> amount = booking->amount;
  this -> account = booking->account;
  //this -> account = new taccount (booking->account);

  //this -> contraaccount = new taccount (booking->contraaccount);
  this -> contraaccount= booking->contraaccount;
  this -> date = booking -> date;
  this -> time = booking -> time;
  this -> text = booking->text;
}

tbooking::~tbooking()
{

}

void tbooking::set(tmoney amount, taccount *account, taccount *contraaccount, tdate date, ttime time, string text)
{
  this -> amount = amount;
  this -> account = account;
  this -> contraaccount = contraaccount;
  this -> date = date;
  this -> time = time;
  this -> text = text;
  this -> printed = false;
  //this -> printed_account = false;
  //this -> printed_contraaccount = false;
  account->setAccountBooking(this);
  contraaccount->setContraBooking(this);
  
  
}

void tbooking::set_amount()
{
  amount.set_amount(amount.get_amount()*(-1));
}

void tbooking::print()
{
  
}