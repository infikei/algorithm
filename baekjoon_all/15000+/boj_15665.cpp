// Solve 2023-02-18
// Update 2024-02-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, m;
int seq[7];
vector<int> nums;

void dfs(int depth = 0) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int num : nums) {
        seq[depth] = num;
        dfs(depth + 1);
    }
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    dfs();

    return 0;
}
