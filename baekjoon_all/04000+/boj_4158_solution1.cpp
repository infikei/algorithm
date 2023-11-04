// Solve 2023-11-03

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
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        vector<int> a, b;
        int x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            cin >> x;
            b.push_back(x);
        }

        int a_pos = 0, b_pos = 0, ans = 0;

        while (true) {
            if (a_pos == SIZE(a) || b_pos == SIZE(b)) break;

            if (a[a_pos] < b[b_pos]) {
                a_pos++;
            }
            else if (a[a_pos] > b[b_pos]) {
                b_pos++;
            }
            else {
                ans++;
                a_pos++;
                b_pos++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
