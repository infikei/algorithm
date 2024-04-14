// Solve 2024-04-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int arr[1000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sums; // 두 수의 합을 저장한다.

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sums.push_back(arr[i] + arr[j]);
        }
    }

    unordered_map<int, int> diffs; // 두 수의 차와 그 두 수 중 큰 값의 최댓값을 저장한다.

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int diff = abs(arr[i] - arr[j]);

            if (diffs.find(diff) == diffs.end()) {
                diffs[diff] = max(arr[i], arr[j]);
            }
            else {
                diffs[diff] = max(diffs[diff], max(arr[i], arr[j]));
            }
        }
    }

    int ans = -1;

    for (int i = SIZE(sums) - 1; i >= 0; i--) {
        if (diffs.find(sums[i]) != diffs.end()) {
            ans = max(ans, diffs[sums[i]]);
        }
    }

    cout << ans << '\n';

    return 0;
}
