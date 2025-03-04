// Solve 2024-02-21
// Update 2025-03-04

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

    int n = 0;

    for (char c : s) {
        n <<= 4;

        if (c >= 'A') {
            n += c - 'A' + 10;
        }
        else {
            n += c - '0';
        }
    }

    cout << n << '\n';

    return 0;
}
