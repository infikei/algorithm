// Solve 2023-02-07

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

int main() {
    FASTIO;

    const int MAX_N = 1e5;
    int n, s, seq[MAX_N];
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int left = 0, right = 1, val = seq[0];
    int ans = INF;
    while (true) {
        if (val >= s) {
            ans = min(ans, right - left);
            val -= seq[left];
            left++;
        }
        else {
            if (right == n) {
                break;
            }
            val += seq[right];
            right++;
        }
    }
    cout << (ans == INF ? 0 : ans) << '\n';

    return 0;
}