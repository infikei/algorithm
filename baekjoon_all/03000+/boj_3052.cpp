// Solve 2022-06-03
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int cnt[42] = { 0 };

    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;

        cnt[num % 42]++;
    }

    int ans = 0;

    for (int &x : cnt) {
        if (x > 0) ans++;
    }

    cout << ans << '\n';

    return 0;
}
