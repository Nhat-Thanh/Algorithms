#include <iostream>
#include <sstream>
#include <string>

int main() {
    int hour, minute, second;
    std::string time_string;
    char c, suffix;
    /* format: hh::mm::ss__, __ is pm or am */
    std::getline(std::cin, time_string);
    std::stringstream ss(time_string);

    ss >> hour >> c;
    ss >> minute >> c;
    ss >> second >> suffix;

    if (second == 60) {
        second = 0;
        ++minute;
    }

    if (minute == 60) {
        ++hour;
        minute = 0;
    }

    if (suffix == 'P' || suffix == 'p') {
        if (hour != 12)
            hour += 12;
    } else if (hour == 12)
        hour = 0;

    std::cout << hour << ':';
    std::cout << minute << ':';
    std::cout << second << '\n';

    return 0;
}
/* 48    0
   49    1
   50    2
   51    3
   52    4
   53    5
   54    6
   55    7
   56    8
   57    9;*/
