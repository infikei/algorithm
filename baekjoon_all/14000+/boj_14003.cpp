// Solve 2023-02-10
// Update 2023-03-23

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
using pii = pair<int, int>;

const int MAX_N = 1000000;
int arr[MAX_N], dp_parent[MAX_N];

int main() {
    FASTIO;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp, dp_idx;
    dp.push_back(arr[0]);
    dp_idx.push_back(0);
    dp_parent[0] = -1;
    for (int i = 1; i < n; i++) {
        int pos = lower_bound(ALL(dp), arr[i]) - dp.begin();
        if (pos == SIZE(dp)) {
            dp.push_back(arr[i]);
            dp_idx.push_back(i);
            dp_parent[i] = dp_idx[pos - 1];
        }
        else if (arr[i] < dp[pos]) {
            dp[pos] = arr[i];
            dp_idx[pos] = i;
            if (pos > 0) {
                dp_parent[i] = dp_idx[pos - 1];
            }
            else {
                dp_parent[i] = -1;
            }
        }
    }
    cout << SIZE(dp) << '\n';

    deque<int> path;
    int idx = dp_idx.back();
    while (idx != -1) {
        path.push_front(idx);
        idx = dp_parent[idx];
    }
    for (auto i : path) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}
