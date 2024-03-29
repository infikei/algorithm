// Solve 2023-02-10
// Update 2023-07-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[1000], dp[1000], dp_parent[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;
    dp_parent[0] = -1;
    for (int i = 1; i < n; i++) {
        dp_parent[i] = -1;

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] > dp[i]) {
                dp[i] = dp[j];
                dp_parent[i] = j;
            }
        }

        dp[i]++;
    }

    int ans = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            idx = i;
        }
    }

    cout << ans << '\n';

    deque<int> path;
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
