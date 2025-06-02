// Solve 2025-05-31

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

string vowel = "aeiou";

bool is_vowel(char c) {
    for (char v : vowel) {
        if (c == v) return true;
    }

    return false;
}

string get_first(string& s) {
    int state = 0;

    for (int i = 0; i < s.length(); i++) {
        if (is_vowel(s[i])) {
            if (state == 0) {
                state = 1;
            }
        }
        else {
            if (state == 1) {
                return s.substr(0, i);
            }
        }
    }

    return "";
}

int main() {
    FASTIO;

    string s1, s2;
    cin >> s1 >> s2;

    string w1 = get_first(s1);
    string w2 = get_first(s2);

    if (w1.empty() || w2.empty()) {
        cout << "no such exercise" << '\n';
    }
    else {
        cout << w1 + w2 << '\n';
    }

    return 0;
}
