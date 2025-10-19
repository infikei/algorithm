// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    for (int i = 0; i + size(str2) <= size(str1); i++) {
        if (str1.substr(i, size(str2)) == str2) {
            return 1;
        }
    }

    return 2;
}
