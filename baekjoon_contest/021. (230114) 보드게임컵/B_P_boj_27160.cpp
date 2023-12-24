// Solve 2023-01-14
// Update 2023-12-24

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

    unordered_map<string, int> hs_map;

    for (int i = 0; i < n; i++) {
        string fruit;
        int x;
        cin >> fruit >> x;

        hs_map[fruit] += x;
    }

    bool ans = false;

    for (auto it = hs_map.begin(); it != hs_map.end(); it++) {
        if (it->second == 5) {
            ans = true;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
