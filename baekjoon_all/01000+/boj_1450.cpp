// Solve 2023-02-07

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

int n, c, weights[30];
vector<ll> left_sums, right_sums;

void add_sum(int left, int right, ll sum, vector<ll> &res_vec) {
    if (left >= right) {
        res_vec.push_back(sum);
        return;
    }
    add_sum(left + 1, right, sum, res_vec);
    add_sum(left + 1, right, sum + weights[left], res_vec);
}

int main() {
    FASTIO;

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    add_sum(0, n / 2, 0, left_sums);
    sort(ALL(left_sums));
    add_sum(n / 2, n, 0, right_sums);
    sort(ALL(right_sums));

    int ans = 0;
    for (auto left_sum : left_sums) {
        if (left_sum > c) {
            break;
        }
        ans += upper_bound(ALL(right_sums), c - left_sum) - right_sums.begin();
    }
    cout << ans << '\n';

    return 0;
}