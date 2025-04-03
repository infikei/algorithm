// Solve 2022-11-01
// Update 2025-04-03

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

    while (true) {
        string line;
        getline(cin, line);

        if (line == "#") break;

        int vowel_cnt = 0;

        for (char &c : line) {
            for (char &v : vowels) {
                if (c == v) {
                    vowel_cnt++;
                    break;
                }
            }
        }

        cout << vowel_cnt << '\n';
    }

    return 0;
}
