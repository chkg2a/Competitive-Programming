#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
  int hour = 0;
  int min = 0;
  int sec = 0;
  int index = 0;
  string timeS = "";
  for (auto character : s) {
    if (index < 2) {
      if (index == 0)
        hour = 10 * (character - '0');
      else if (index == 1)
        hour += (character - '0');
    } else if (index < 5) {
      if (index == 3)
        min = 10 * (character - '0');
      else if (index == 4)
        min += (character - '0');
    } else if (index < 8) {
      if (index == 6)
        sec = 10 * (character - '0');
      else if (index == 7)
        sec += (character - '0');
    } else if (index < 11) {
      if (index == 8) {
        if (character == 'A') {
          if (hour > 23 || hour == 12) {
            hour = 0;
          }
        } else {
          if (hour != 12) {
            hour += 12;
          }
          if (hour > 23) {
            hour = 0;
          }
        }
      }
    }
    index++;
  }

  if (hour < 10) {
    timeS.append("0" + to_string(hour));
    timeS.append(":");
  } else {
    timeS.append(to_string(hour));
    timeS.append(":");
  }
  if (min < 10) {
    timeS.append("0" + to_string(min));
    timeS.append(":");
  } else {
    timeS.append(to_string(min));
    timeS.append(":");
  }
  if (sec < 10) {
    timeS.append("0" + to_string(sec));
  } else {
    timeS.append(to_string(sec));
  }
  cout << timeS;
  return s;
}

int main(int argc, char *argv[]) {
  string time = "01:59:59PM";
  timeConversion(time);
  // cout << timeConversion(time);
  return 0;
}
