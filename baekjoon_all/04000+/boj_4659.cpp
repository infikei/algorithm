// Solve 2023-04-06
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

inline bool is_vowel(char c) {
    string aeiou = "aeiou";

    for (const char &a : aeiou) {
        if (c == a)return true;
    }

    return false;
}

int main() {
    FASTIO;

    while (true) {
        string password;
        cin >> password;
        if (password == "end") break;

        bool check = false;

        for (int i = 0, ie = SIZE(password); i < ie; i++) {
            if (is_vowel(password[i])) check = true;

            if (i >= 2) {
                bool cur = is_vowel(password[i]), prev = is_vowel(password[i - 1]), prev2 = is_vowel(password[i - 2]);

                if (cur == prev && cur == prev2) {
                    check = false;
                    break;
                }
            }

            if (i >= 1 && password[i] == password[i - 1] && password[i] != 'e' && password[i] != 'o') {
                check = false;
                break;
            }
        }

        cout << '<' << password << "> is ";
        if (!check) cout << "not ";
        cout << "acceptable.\n";
    }

    return 0;
}
