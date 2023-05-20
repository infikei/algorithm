// Solve 2023-05-19

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

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int card_num[16];
        for (int i = 0; i < 16; i++) {
            char c;
            cin >> c;

            card_num[i] = c - '0';
        }

        for (int i = 0; i < 16; i += 2) {
            card_num[i] *= 2;
            if (card_num[i] >= 10) {
                card_num[i] = card_num[i] / 10 + card_num[i] % 10;
            }
        }

        int val = 0;
        for (int i = 0; i < 16; i++) {
            val += card_num[i];
        }

        if (val % 10 == 0) {
            cout << "T\n";
        }
        else {
            cout << "F\n";
        }
    }

    return 0;
}
