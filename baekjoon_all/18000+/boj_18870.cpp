// Solve 2023-02-23
// Update 2023-12-21

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

    vector<int> nums(n);

    for (int &num : nums) {
        cin >> num;
    }

    vector<int> sorted_unique_nums = nums;
    sort(sorted_unique_nums.begin(), sorted_unique_nums.end());
    sorted_unique_nums.erase(unique(sorted_unique_nums.begin(), sorted_unique_nums.end()), sorted_unique_nums.end());
    unordered_map<int, int> hs;

    for (int i = 0, i_end = SIZE(sorted_unique_nums); i < i_end; i++) {
        hs[sorted_unique_nums[i]] = i;
    }

    for (int &num : nums) {
        cout << hs[num] << ' ';
    }

    cout << '\n';

    return 0;
}
