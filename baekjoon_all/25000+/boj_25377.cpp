// Solve 2022-11-13
// Update 2024-03-11

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

    int ans = 1001;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a <= b) {
            ans = min(ans, b);
        }
    }

    cout << (ans == 1001 ? -1 : ans) << '\n';

    return 0;
}
