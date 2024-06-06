// Solve 2024-06-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int nums[3];

    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + 3);

    cout << (nums[0] + nums[1] == nums[2]) << '\n';

    return 0;
}
