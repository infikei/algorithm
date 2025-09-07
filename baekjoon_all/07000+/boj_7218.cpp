// Solve 2025-09-07

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

string roman_numbers[13] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;
    bool hidden[13] = {false};

    for (int i = 0; i < size(s); i++) {
        for (int d = 1; d <= 12; d++) {
            if (i + size(roman_numbers[d]) <= size(s)) {
                string w = s.substr(i, size(roman_numbers[d]));

                if (w == roman_numbers[d]) {
                    hidden[d] = true;
                }
            }
        }
    }

    for (int d = 1; d <= 12; d++) {
        if (hidden[d]) {
            cout << d << ' ';
        }
    }

    cout << '\n';
    return 0;
}
