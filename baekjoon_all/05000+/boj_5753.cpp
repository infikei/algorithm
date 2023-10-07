// Solve 2023-10-07

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
        int n, d;
        cin >> n >> d;

        if (n == 0 && d == 0) break;

        vector<int> cnt(n, 0);

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;

                if (x == 1) cnt[j]++;
            }
        }

        bool ans = false;

        for (int j = 0; j < n; j++) {
            if (cnt[j] == d) {
                ans = true;
                break;
            }
        }

        if (ans) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
