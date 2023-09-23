// Solve 2023-09-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int k;
        string s;
        cin >> k >> s;

        int n10 = stoi(s), n16 = 0, n8 = 0;

        for (char &c : s) {
            n16 *= 16;
            n16 += c - '0';
        }

        for (char &c : s) {
            if (c >= '8') {
                n8 = 0;
                break;
            }

            n8 *= 8;
            n8 += c - '0';
        }

        cout << k << ' ' << n8 << ' ' << n10 << ' ' << n16 << '\n';
    }

    return 0;
}
