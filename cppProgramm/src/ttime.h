#ifndef TTIME_H_
#define TTIME_H_

class ttime {
  public:
	ttime();
	ttime(int sec, int min, int hour); 							// allgemeiner Konstruktor

	void zeitSetzen(int newSec, int newMin, int newHour);		// moegleichkeit Zeit festlegen
	void zeitHolen();

  private:
	int sec;
	int min;
	int hour;
};

#endif /* TTIME_H_ */
