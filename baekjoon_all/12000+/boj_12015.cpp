// Solve 2022-12-08
// Update 2023-02-10

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

const int N_MAX = 1000000;
int n, arr[N_MAX];
vector<int> dp;

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        int pos = lower_bound(ALL(dp), arr[i]) - dp.begin();
        if (pos == SIZE(dp)) {
            dp.push_back(arr[i]);
        }
        else if (arr[i] < dp[pos]) {
            dp[pos] = arr[i];
        }
    }

    cout << SIZE(dp) << '\n';

    return 0;
}