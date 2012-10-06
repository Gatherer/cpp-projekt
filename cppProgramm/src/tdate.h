#ifndef TDATE_H_
#define TDATE_H_

class tdate {
  public:
	TDATE();
	TDATE(int day, int month, int year); 							// allgemeiner Konstruktor

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void datumSetzen(int newDay, int newMonth, int newYear);		// moegleichkeit Datum festlegen

  private:
	int day;
	int month;
	int year;
};

#endif /* TDATE_H_ */
