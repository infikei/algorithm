// Solve 2023-01-09
// Update 2023-08-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int sum_of_num[2] = { 28, 21 };

    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;

        sum_of_num[i % 2] += x;
    }

    int ans = sum_of_num[0] + sum_of_num[1] * 3;

    cout << "The 1-3-sum is " << ans << '\n';

    return 0;
}
