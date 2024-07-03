// Solve 2023-10-07
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, x;
    cin >> n >> x;

    int sum_of_p = 0;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        sum_of_p += p;
    }

    cout << (sum_of_p % x == 0 ? 1 : 0) << '\n';

    return 0;
}
