// Solve 2023-02-07
// Update 2023-11-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;
const int MAX_N = 1e5;

int main() {
    FASTIO;

    int n, s;
    cin >> n >> s;

    int arr[MAX_N];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 1;
    int val = arr[0];
    int ans = INF;

    while (true) {
        if (val >= s) {
            ans = min(ans, right - left);
            val -= arr[left];
            left++;
        }
        else {
            if (right == n) break;

            val += arr[right];
            right++;
        }
    }

    if (ans == INF) cout << 0 << '\n';
    else cout << ans << '\n';

    return 0;
}
