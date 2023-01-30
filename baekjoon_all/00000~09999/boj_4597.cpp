#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    while (true) {
        string bit_string;
        cin >> bit_string;
        if (bit_string == "#") break;

        char parity_type = bit_string.back();
        bit_string.pop_back();

        int cnt_1 = 0;
        for (auto a : bit_string) {
            if (a == '1') cnt_1++;
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