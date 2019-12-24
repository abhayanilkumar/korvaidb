#ifndef KDB_IOTOOLS_H
#define KDB_IOTOOLS_H

#include <iostream>

namespace kdb{
    const int IOWIDTH = 50; // default viewport width

    std::ostream& line(const char* str = "-", int num = IOWIDTH); // prints a given character, ch, num number of times
    std::ostream& center(const char*, int width = IOWIDTH); // prints a string into the center of width viewport
    void read(int& val, int min, int max, const char* ErrorMess, std::istream& is = std::cin);
    void read(long long& val, long long min, long long max, const char* ErrorMess, std::istream& is = std::cin);
    void read(char* str, int len, const char* errorMessage, std::istream& is = std::cin);
}

#endif