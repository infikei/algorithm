// Solve 2023-02-10
// Update 2024-12-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int get_lis(int n, vector<int> &nums) {
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(all(lis), nums[i]) - lis.begin();

        if (idx == size(lis)) {
            lis.push_back(nums[i]);
        }
        else {
            lis[idx] = nums[i];
        }
    }

    return size(lis);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    println(get_lis(n, nums));

    return 0;
}
