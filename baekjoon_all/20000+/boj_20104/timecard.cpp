// Solve 2024-10-17

#include "timecard.h"

void init(int n) {
}

std::string convert(std::string s) {
    for (char &c : s) {
        if (c >= 'A' & c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    return s;
}
