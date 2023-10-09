// Solve 2023-01-14
// Update 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc_sum(int k, int mod) {
    int res = 0;

    while (k > 0) {
        res += k % mod;
        k /= mod;
    }

    return res;
}

int main() {
    FASTIO;

    for (int num = 1000; num < 10000; num++) {
        int sum10 = calc_sum(num, 10);
        int sum12 = calc_sum(num, 12);

        if (sum10 != sum12) continue;

        int sum16 = calc_sum(num, 16);

        if (sum10 != sum16) continue;

        cout << num << '\n';
    }

    return 0;
}
