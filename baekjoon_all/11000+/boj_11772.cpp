// Solve 2024-02-17

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

    int ans = 0;

    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;

        int d = p.back() - '0';
        p.pop_back();
        int k = stoi(p);

        int kd = 1;

        for (int j = 0; j < d; j++) {
            kd *= k;
        }

        ans += kd;
    }

    cout << ans << '\n';

    return 0;
}
