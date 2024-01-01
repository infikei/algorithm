// Solve 2023-12-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

void dfs(int &n, int &ans, int &len, int depth = 0, string k_str = "") {
    if (depth == len) {
        int k = stoi(k_str);

        if (k <= n) {
            ans = k;
        }

        return;
    }

    dfs(n, ans, len, depth + 1, k_str + "7");

    if (ans == -1) {
        dfs(n, ans, len, depth + 1, k_str + "4");
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = -1;

    for (int len = 6; len >= 1; len--) {
        dfs(n, ans, len);

        if (ans != -1) break;
    }

    cout << ans << '\n';

    return 0;
}
