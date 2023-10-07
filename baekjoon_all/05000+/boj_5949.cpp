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

    string s;
    cin >> s;

    string ans;
    int pos = 0;

    if (SIZE(s) % 3 == 1) {
        ans.push_back(s[pos++]);
        ans.push_back(',');
    }
    else if (SIZE(s) % 3 == 2) {
        ans.push_back(s[pos++]);
        ans.push_back(s[pos++]);
        ans.push_back(',');
    }

    while (pos < SIZE(s)) {
        ans.push_back(s[pos++]);
        ans.push_back(s[pos++]);
        ans.push_back(s[pos++]);
        ans.push_back(',');
    }

    ans.pop_back();

    cout << ans << '\n';

    return 0;
}
