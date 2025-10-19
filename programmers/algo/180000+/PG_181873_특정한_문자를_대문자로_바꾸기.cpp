// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string alp) {
    char al = alp[0];

    for (char& c : my_string) {
        if (c == al) {
            c = c - 'a' + 'A';
        }
    }

    return my_string;
}
