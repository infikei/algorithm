// Solve 2022-06-03
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MAX = 10001;

int main() {
    FASTIO;

    bool check[MAX] = { false };

    for (int num = 1; num < MAX; num++) {
        int next = num, tmp = num;

        while (tmp > 0) {
            next += tmp % 10;
            tmp /= 10;
        }

        if (next < MAX) {
            check[next] = true;
        }
    }

    for (int i = 1; i < MAX; i++) {
        if (!check[i]) cout << i << '\n';
    }

    return 0;
}
