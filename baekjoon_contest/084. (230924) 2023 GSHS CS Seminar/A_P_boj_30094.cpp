// Solve 2023-09-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const ll MOD = 998244353;

struct Num{
    ll val = 0;
    int idx = 0;
    bool operator<(const Num &rhs) const {
        return val < rhs.val;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Num> nums(n);
    ll max_val = 0, n1 = n - 1;

    for (int i = 0; i < n; i++) {
        ll c, a;
        cin >> c >> a;

        max_val += a * n1;

        nums[i].val = c - a;
        nums[i].idx = i + 1;
    }

    ll min_val = max_val;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        max_val += nums[i].val * i;
        min_val += nums[i].val * (n1 - i);
    }

    ll cnt = 1, cur = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i - 1].val == nums[i].val) {
            cnt *= ++cur;
            cnt %= MOD;
        }
        else {
            cur = 1;
        }
    }

    cout << min_val << ' ' << cnt << '\n';

    for (int i = n - 1; i >= 0; i--) {
        cout << nums[i].idx << ' ';
    }

    cout << '\n';

    cout << max_val << ' ' << cnt << '\n';

    for (int i = 0; i < n; i++) {
        cout << nums[i].idx << ' ';
    }

    cout << '\n';

    return 0;
}
