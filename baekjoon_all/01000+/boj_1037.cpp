// Solve 2022-06-06
// Update 2023-10-14

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

    int nums[50];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    cout << nums[0] * nums[n - 1] << '\n';

    return 0;
}
