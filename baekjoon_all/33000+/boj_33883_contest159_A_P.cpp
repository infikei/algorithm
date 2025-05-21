// Solve 2025-05-17

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

int main() {
    FASTIO;

    string s;
    cin >> s;

    string vowel = "aeiou";
    vector<int> idx_of_vowel;

    for (int i = 0; i < s.size(); i++) {
        for (char& v : vowel) {
            if (s[i] == v) {
                idx_of_vowel.push_back(i + 1);
                break;
            }
        }
    }

    string accent = "aeiouns";

    for (char& v : accent) {
        if (s.back() == v) {
            if (idx_of_vowel.size() < 2) {
                cout << -1 << '\n';
                return 0;
            }

            cout << idx_of_vowel[idx_of_vowel.size() - 2] << '\n';
            return 0;
        }
    }

    if (idx_of_vowel.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    cout << idx_of_vowel.back() << '\n';
    return 0;
}
