// Solve 2024-05-18

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
    string s;
    cin >> n >> s;

    int cnt[26] = { 0 };
    string ans;

    for (char c : s) {
        if (cnt[c - 'a'] == 0) {
            cnt[c - 'a']++;
            ans.push_back(c);
        }
    }

    ans = to_string(n + 1906) + ans + to_string(SIZE(s) - SIZE(ans) + 4);
    reverse(ans.begin(), ans.end());
    ans = "smupc_" + ans;
    cout << ans << '\n';

    return 0;
}
