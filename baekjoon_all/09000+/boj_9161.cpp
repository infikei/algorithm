// Solve 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    for (int aaa = 100; aaa <= 999; aaa++) {
        for (int bbb = 100; bbb <= 999; bbb++) {
            if (aaa % 10 != bbb / 100) continue;
            if (aaa % 111 == 0) continue;

            int aa = aaa / 10;
            int bb = bbb % 100;

            if (aaa * bb == bbb * aa) {
                cout << aaa << " / " << bbb << " = " << aa << " / " << bb << '\n';
            }
        }
    }

    return 0;
}
