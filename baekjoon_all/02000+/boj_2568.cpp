// Solve 2023-02-10

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
using pii = pair<int, int>;

int n, dp[100000], dp_size, a_to_b_cnt[100000];
pii a_to_b[100000];

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a_to_b[i] = { a, b };
    }
    sort(a_to_b, a_to_b + n);

    dp[dp_size] = a_to_b[0].second;
    a_to_b_cnt[0] = dp_size;
    dp_size++;
    for (int i = 1; i < n; i++) {
        int pos = lower_bound(dp, dp + dp_size, a_to_b[i].second) - dp;
        if (pos == dp_size) {
            dp_size++;
        }
        dp[pos] = a_to_b[i].second;
        a_to_b_cnt[i] = pos;
    }

    cout << n - dp_size << '\n';

    stack<int> numbers_to_exclude;
    int pos = dp_size - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a_to_b_cnt[i] == pos) {
            pos--;
        }
        else {
            numbers_to_exclude.push(a_to_b[i].first);
        }
    }
    while (!numbers_to_exclude.empty()) {
        cout << numbers_to_exclude.top() << '\n';
        numbers_to_exclude.pop();
    }

    return 0;
}