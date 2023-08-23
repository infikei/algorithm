// Solve 2023-01-10
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string bit_string;
        cin >> bit_string;
        if (bit_string == "#") break;

        char parity_type = bit_string.back();
        bit_string.pop_back();

        int cnt_1 = 0;

        for (const char c : bit_string) {
            if (c == '1') cnt_1++;
        }

        if (parity_type == 'e') {
            if (cnt_1 % 2 == 0) bit_string.push_back('0');
            else bit_string.push_back('1');
        }
        else {
            if (cnt_1 % 2 == 0) bit_string.push_back('1');
            else bit_string.push_back('0');
        }

        cout << bit_string << '\n';
    }

    return 0;
}
