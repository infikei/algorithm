// Solve 2024-03-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n;
int a[101];
int p[101];

int move_sero(int x) {
    int res = 0;

    for (int i = 1; i <= n; i++) {
        if (x >= a[i]) {
            res += (a[i] - a[i - 1]) * p[i];
        }
        else {
            res += (x - a[i - 1]) * p[i];
            break;
        }
    }

    return res;
}

int main() {
    FASTIO;

    int w, h, d;
    cin >> w >> h >> n >> d;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int ans = 1000000000;

    for (int i = 1; i <= n; i++) {
        int cur = move_sero(a[i - 1]) + abs(move_sero(a[i - 1]) - move_sero(d)) + w * p[i];

        ans = min(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
