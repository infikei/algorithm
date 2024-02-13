// Solve 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        if (ti >= 2) cout << '\n';

        cout << "Scenario #" << ti << ":\n";

        int m;
        cin >> m;

        vector<string> words(m);

        for (string &w : words) {
            cin >> w;
        }

        int n, k, idx;
        cin >> n;

        while (n-- > 0) {
            cin >> k;

            while (k-- > 0) {
                cin >> idx;
                cout << words[idx];
            }

            cout << '\n';
        }
    }

    return 0;
}
