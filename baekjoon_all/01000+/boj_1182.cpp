// Solve 2023-03-29

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int n, s, arr[20], ans;

void dfs(int depth = 0, int val = 0, int cnt = 0) {
    if (depth == n) {
        if (val == s && cnt > 0) {
            ans++;
        }
        return;
    }

    dfs(depth + 1, val, cnt);
    dfs(depth + 1, val + arr[depth], cnt + 1);
}

int main() {
    FASTIO;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs();
    cout << ans << '\n';

    return 0;
}
