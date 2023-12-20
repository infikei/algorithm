// Solve 2022-06-03
// Update 2023-12-20

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

    int nums[500000];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int target_num;
        cin >> target_num;

        if (binary_search(nums, nums + n, target_num)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    cout << '\n';

    return 0;
}
