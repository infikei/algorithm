// Solve 2024-03-01

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

    for (int ti = 1; ti <= t; ti++) {
        string s;
        cin >> s;

        int num = 0;
        int a = 0;
        int b = 0;

        for (int i = 0; i < SIZE(s); i++) {
            if (s[i] != '!') {
                num = s[i] - '0';
                a = i;
                b = SIZE(s) - i - 1;
                break;
            }
        }

        if (b > 0) {
            num = 1;
        }

        if (a % 2 == 1) {
            num = 1 - num;
        }

        cout << num << '\n';
    }

    return 0;
}
