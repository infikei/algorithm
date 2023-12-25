// Solve 2023-09-17
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<int> room(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int k, s, e;
        cin >> k >> s >> e;

        if (s >= room[k]) {
            cout << "YES\n";
            room[k] = e;
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
