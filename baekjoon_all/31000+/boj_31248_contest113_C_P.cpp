// Solve 2024-01-14
// Update 2024-01-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

void hanoi_3(int depth, char from, char to, char tmp) {
    if (depth == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi_3(depth - 1, from, tmp, to);
    cout << from << ' ' << to << '\n';
    hanoi_3(depth - 1, tmp, to, from);
}

void hanoi_4(int depth, char from, char to, char tmp1, char tmp2) {
    if (depth == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    if (depth == 2) {
        cout << from << ' ' << tmp2 << '\n';
        cout << from << ' ' << to << '\n';
        cout << tmp2 << ' ' << to << '\n';
        return;
    }

    hanoi_3(depth - 2, from, tmp1, tmp2);
    cout << from << ' ' << tmp2 << '\n';
    cout << from << ' ' << to << '\n';
    cout << tmp2 << ' ' << to << '\n';
    hanoi_4(depth - 2, tmp1, to, from, tmp2);
}

int main() {
    FASTIO;

    int dp[21] = { 0, 1, 3 };

    for (int i = 3; i <= 20; i++) {
        dp[i] = dp[i - 2] + 3 + (1 << (i - 2)) - 1;
    }

    int n;
    cin >> n;

    cout << dp[n] << '\n';
    hanoi_4(n, 'A', 'D', 'B', 'C');

    return 0;
}
