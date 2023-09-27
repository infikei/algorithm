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

    while (true) {
        int age;
        cin >> age;

        if (age == 0) break;

        int ans = 1;

        for (int i = 0; i < age; i++) {
            int x, y;
            cin >> x >> y;

            ans *= x;
            ans -= y;
        }

        cout << ans << '\n';
    }

    return 0;
}
