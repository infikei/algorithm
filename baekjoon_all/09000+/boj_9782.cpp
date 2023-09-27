// Solve 2023-09-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(1);

    int ti = 0;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> vec(n);

        for (int &x : vec) {
            cin >> x;
        }

        double ans;

        if (n % 2 == 0) {
            ans = (vec[n / 2 - 1] + vec[n / 2]) * 0.5;
        }
        else {
            ans = vec[n / 2];
        }

        cout << "Case " << ++ti << ": " << ans << '\n';
    }

    return 0;
}
