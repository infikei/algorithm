// Solve 2023-02-19

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

    int n;
    cin >> n;

    int ans = 0;
    string s = "2023";

    for (int k = 2023; k <= n; k++) {
        string k_str = to_string(k);

        int res = 0;

        for (auto ch : k_str) {
            if (ch == s[res]) {
                res++;
                if (res == 4) {
                    break;
                }
            }
        }

        if (res == 4) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}