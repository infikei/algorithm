// Solve 2023-05-04

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    string s, ans;
    int ans_len = 0;
    regex re("[a-zA-Z\\-]+");
    smatch match;

    while (true) {
        cin >> s;
        if (s == "E-N-D") {
            break;
        }

        while (regex_search(s, match, re)) {
            string tmp = match.str();
            if (ans_len < SIZE(tmp)) {
                ans = tmp;
                ans_len = SIZE(ans);
            }

            s = match.suffix();
        }
    }

    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    cout << ans << '\n';

    return 0;
}
