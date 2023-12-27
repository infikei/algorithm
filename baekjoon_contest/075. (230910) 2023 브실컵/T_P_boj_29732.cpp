// Solve 2023-09-10
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    vector<int> check(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            for (int j = max(0, i - k), je = min(n - 1, i + k); j <= je; j++) {
                if (++check[j] == 1) {
                    cnt++;
                }
            }
        }
    }

    cout << (cnt <= m ? "Yes" : "No") << '\n';

    return 0;
}
