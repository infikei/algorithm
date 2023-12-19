// Solve 2023-08-07
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int dfs(int n, vector<int> &nums, vector<bool> &visited, int depth = 0, int abs_sum = 0, int prev_num = 0) {
    if (depth == n) {
        return abs_sum;
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int new_abs_sum = 0;

        if (depth >= 1) {
            new_abs_sum = abs_sum + abs(nums[i] - prev_num);
        }

        visited[i] = true;
        int new_res = dfs(n, nums, visited, depth + 1, new_abs_sum, nums[i]);
        visited[i] = false;

        res = max(res, new_res);
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int &num : nums) {
        cin >> num;
    }

    vector<bool> visited(n, false);
    int ans = dfs(n, nums, visited);

    cout << ans << '\n';

    return 0;
}
