// Solve 2023-02-18

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int n, m, nums[8], seq[8];
bool visited[8];

void dfs(int depth = 0, int begin_idx = 0) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = begin_idx; i < n; i++) {
        if (visited[i] || seq[depth] == nums[i]) continue;

        visited[i] = true;
        seq[depth] = nums[i];
        dfs(depth + 1, i + 1);
        visited[i] = false;
    }
    seq[depth] = 0;
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);

    dfs();

    return 0;
}