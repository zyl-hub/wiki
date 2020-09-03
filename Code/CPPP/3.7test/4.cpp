#include <iostream>
using namespace std;

const long DayToHour = 24;
const long HourToMin = 60;
const long MinToSec = 60;
const long DayToSec = 60 * 60 * 24;
void showTime(long);

int main() {
  long seconds = 0;
  cin >> seconds;
  showTime(seconds);

  return 0;
}

void showTime(long seconds) {
  cout << seconds / MinToSec / HourToMin / DayToHour << "days" << endl;
  cout << long(seconds / MinToSec / HourToMin) << ","
       << long((seconds % (MinToSec * HourToMin) / MinToSec)) << ","
       << long((seconds % (MinToSec * HourToMin) % MinToSec));
}
