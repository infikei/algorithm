// Solve 2023-10-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string a, b;
        cin >> a >> b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = to_string(stoi(a) + stoi(b));

        reverse(ans.begin(), ans.end());

        cout << stoll(ans) << '\n';
    }

    return 0;
}
