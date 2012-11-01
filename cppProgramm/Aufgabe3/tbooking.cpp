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
  account->setAccountBooking(this);
  contraaccount->setContraBooking(this);
}

void tbooking::print()
{
  
}