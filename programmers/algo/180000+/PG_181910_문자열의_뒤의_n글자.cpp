// Solve 2025-10-19

#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, int n) {
    return my_string.substr(size(my_string) - n, n);
}
