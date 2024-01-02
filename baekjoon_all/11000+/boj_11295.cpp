// Solve 2024-01-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int user = 0;

    while (true) {
        int l;
        cin >> l;

        if (l == 0) break;

        cout << "User " << ++user << '\n';

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            int ans = l * x;

            cout << ans / 100000 << '.' << setfill('0') << setw(5) << ans % 100000 << '\n';
        }
    }

    return 0;
}
