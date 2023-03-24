// Solve 2022-08-09
// Update 2023-03-23

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int cows[11];
    for (int i = 1; i < 11; i++) {
        cows[i] = -1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cow, location;
        cin >> cow >> location;

        if (cows[cow] == -1) {
            cows[cow] = location;
        }
        else if (cows[cow] != location) {
            cows[cow] = location;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
