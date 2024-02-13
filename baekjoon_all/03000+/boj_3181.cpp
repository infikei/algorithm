// Solve 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string words_ignore[10] = {
        "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"
    };

    string s, ans;
    getline(cin, s, ' ');
    ans.push_back(s[0] - 'a' + 'A');

    while (getline(cin, s, ' ')) {
        bool flag_continue = false;

        for (string w : words_ignore) {
            if (s == w) {
                flag_continue = true;
                break;
            }
        }

        if (flag_continue) continue;

        ans.push_back(s[0] - 'a' + 'A');
    }

    cout << ans << '\n';

    return 0;
}
