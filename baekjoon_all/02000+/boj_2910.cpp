// Solve 2023-09-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Num{
    int val = 0, idx = 0, cnt = 0;
    Num(int v, int i, int c) : val(v), idx(i), cnt(c) {}
    bool operator<(const Num &rhs) const {
        if (cnt != rhs.cnt) return cnt > rhs.cnt;
        return idx < rhs.idx;
    }
};

int main() {
    FASTIO;

    int n, c;
    cin >> n >> c;

    unordered_map<int, int> hs_cnt;
    unordered_map<int, int> hs_idx;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        hs_cnt[x]++;

        if (hs_idx.find(x) == hs_idx.end()) {
            int i = SIZE(hs_idx);
            hs_idx[x] = i + 1;
        }
    }

    vector<Num> nums;

    for (auto it = hs_cnt.begin(); it != hs_cnt.end(); it++) {
        int val = it->first;
        int cnt = it->second;
        int idx = hs_idx[val];

        nums.emplace_back(val, idx, cnt);
    }

    sort(nums.begin(), nums.end());

    for (Num &num : nums) {
        int val = num.val;
        int cnt = num.cnt;

        for (int i = 0; i < cnt; i++) {
            cout << val << ' ';
        }
    }

    cout << '\n';

    return 0;
}
