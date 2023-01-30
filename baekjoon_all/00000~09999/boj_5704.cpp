#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string s;

    while (true) {
        getline(cin, s);
        if (s == "*") break;

        bool check[26] = {false};
        for (auto a : s) {
            if (a == ' ') continue;
            check[a - 'a'] = true;
        }

        bool is_pangram = true;
        for (int i = 0; i < 26; i++) {
            if (!check[i]) {
                is_pangram = false;
                break;
            }
        }

        if (is_pangram) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}