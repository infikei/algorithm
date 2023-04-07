// Solve 2023-04-06

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

inline bool is_vowel(char ch) {
    string aeiou = "aeiou";
    for (auto a : aeiou) {
        if (ch == a) {
            return true;
        }
    }
    return false;
}

int main() {
    FASTIO;

    while (true) {
        string password;
        cin >> password;
        if (password == "end") {
            break;
        }

        bool check = false;

        for (int i = 0, i_end = SIZE(password); i < i_end; i++) {
            if (is_vowel(password[i])) {
                check = true;
            }

            bool cur = is_vowel(password[i]), prev = is_vowel(password[i - 1]), prev2 = is_vowel(password[i - 2]);

            if (i > 1 && cur == prev && cur == prev2) {
                check = false;
                break;
            }

            if (i > 0 && password[i] == password[i - 1] && password[i] != 'e' && password[i] != 'o') {
                check = false;
                break;
            }
        }

        cout << '<' << password << "> is ";
        if (!check) {
            cout << "not ";
        }
        cout << "acceptable.\n";
    }

    return 0;
}
