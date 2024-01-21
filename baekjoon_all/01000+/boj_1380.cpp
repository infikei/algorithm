// Solve 2024-01-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int test_idx = 0;

    while (true) {
        int n;
        cin >> n;
        cin.ignore();

        if (n == 0) break;

        vector<string> names(n + 1);
        vector<int> cnt(n + 1);

        for (int i = 1; i <= n; i++) {
            getline(cin, names[i]);
        }

        for (int i = 0, ie = n * 2 - 1; i < ie; i++) {
            int idx;
            char ch;
            cin >> idx >> ch;

            cnt[idx]++;
        }

        for (int i = 1; i <= n; i++) {
            if (cnt[i] % 2 == 1) {
                cout << ++test_idx << ' ' << names[i] << '\n';
                break;
            }
        }
    }

    return 0;
}
