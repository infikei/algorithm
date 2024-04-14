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

    int n, k;
    string s;
    cin >> n >> k >> s;

    string ans;

    for (char &c : s) {
        while (!ans.empty() && ans.back() < c && k > 0) {
            k--;
            ans.pop_back();
        }

        ans.push_back(c);
    }

    while (k > 0) {
        k--;
        ans.pop_back();
    }

    cout << ans << '\n';

    return 0;
}
