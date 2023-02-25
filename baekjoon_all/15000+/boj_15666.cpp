// Solve 2022-08-12
// Update 2023-02-18

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
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()); // 정렬이 이미 되어있는 상태에서 중복 제거
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int n, m, seq[8];
vector<int> nums;

void dfs(int depth = 0, int begin_idx = 0) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = begin_idx; i < n; i++) {
        seq[depth] = nums[i];
        dfs(depth + 1, i);
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
    sort(ALL(nums));
    UNIQUE(nums);
    n = SIZE(nums);

    dfs();

    return 0;
}