// Solve 2024-01-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, k;
int len_str_n;
int digits[3];
int ans = -1;

bool dfs(int depth, int num) {
    if (depth == len_str_n) {
        if (num <= n) {
            ans = num;
            return true;
        }

        return false;
    }

    for (int d : digits) {
        if (dfs(depth + 1, num * 10 + d)) {
            return true;
        }
    }

    if (num == 0) {
        if (dfs(depth + 1, 0)) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n >> k;
    len_str_n = SIZE(to_string(n));

    for (int i = 0; i < k; i++) {
        cin >> digits[i];
    }

    sort(digits, digits + k, greater<int>());
    dfs(0, 0);
    cout << ans << '\n';

    return 0;
}
