// Solve 2022-12-17
// Update 2025-02-25

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string s, bomb;
    cin >> s >> bomb;

    string ans;

    for (char c : s) {
        ans.push_back(c);

        if (SIZE(ans) < SIZE(bomb)) continue;

        if (c == bomb.back() && ans.substr(SIZE(ans) - SIZE(bomb), SIZE(bomb)) == bomb) {
            for (int i = 0; i < SIZE(bomb); i++) {
                ans.pop_back();
            }
        }
    }

    cout << (ans.empty() ? "FRULA" : ans) << '\n';

    return 0;
}
