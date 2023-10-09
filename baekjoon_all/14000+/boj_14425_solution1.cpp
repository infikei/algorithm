// Solve 2022-06-03
// Update 2023-10-09

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

    unordered_set<string> str_set;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        str_set.insert(str);
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if (str_set.find(str) != str_set.end()) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
