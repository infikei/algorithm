// Solve 2022-12-17
// Update 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s, bomb;
    cin >> s >> bomb;

    string ans;

    for (char ch : s) {
        ans.push_back(ch);

        if (SIZE(ans) < SIZE(bomb)) continue;

        if (ch == bomb.back() && ans.substr(SIZE(ans) - SIZE(bomb), SIZE(bomb)) == bomb) {
            for (int i = 0; i < SIZE(bomb); i++) {
                ans.pop_back();
            }
        }
    }

    cout << (ans.empty() ? "FRULA" : ans) << '\n';

    return 0;
}
