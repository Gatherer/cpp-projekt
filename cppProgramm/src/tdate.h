#ifndef TDATE_H_
#define TDATE_H_

class tdate {
  public:
	tdate();
	tdate(int day, int month, int year); 							// allgemeiner Konstruktor

	void datumSetzen(int newDay, int newMonth, int newYear);		// moegleichkeit Datum festlegen
	void datumHolen();

  private:
	int day;
	int month;
	int year;
};

#endif /* TDATE_H_ */
