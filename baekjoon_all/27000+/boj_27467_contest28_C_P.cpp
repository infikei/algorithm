// Solve 2023-02-11
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

    int n;
    cin >> n;

    int cnt[3] = { 0 };

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a % 3]++;
    }

    int p = cnt[1] - cnt[2];
    int q = cnt[0] - cnt[2];
    cout << p << ' ' << q << '\n';

    return 0;
}
