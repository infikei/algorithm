// Solve 2025-04-03

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

string vowels = "AEIOUaeiou";

int main() {
    FASTIO;

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        int consonant_cnt = 0;
        int vowel_cnt = 0;

        string line;
        getline(cin, line);

        for (char &c : line) {
            if (c == ' ') continue;

            bool is_vowel = false;

            for (char &v : vowels) {
                if (c == v) {
                    is_vowel = true;
                    break;
                }
            }

            if (is_vowel) {
                vowel_cnt++;
            }
            else {
                consonant_cnt++;
            }
        }

        cout << consonant_cnt << ' ' << vowel_cnt << '\n';
    }

    return 0;
}
