// Solve 2022-11-08
// Update 2024-04-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int n = 0;
    int cnt = 0;

    if (SIZE(s) <= 1) {
        n = stoi(s);
    }
    else {
        for (char c : s) {
            n += c - '0';
        }

        cnt++;

        while (n >= 10) {
            int nn = 0;

            while (n > 0) {
                nn += n % 10;
                n /= 10;
            }

            n = nn;
            cnt++;
        }
    }

    cout << cnt << '\n' << (n % 3 == 0 ? "YES\n" : "NO\n");

    return 0;
}
