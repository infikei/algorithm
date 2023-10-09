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

    string str_list[10000];

    for (int i = 0; i < n; i++) {
        cin >> str_list[i];
    }

    sort(str_list, str_list + n);

    int ans = 0;

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if (binary_search(str_list, str_list + n, str)) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
