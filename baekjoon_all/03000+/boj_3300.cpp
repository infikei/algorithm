// Solve 2023-04-27

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

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s1, s2;
        cin >> s1 >> s2;
        char ans = '!';

        for (char ch = 'A'; ch <= 'Z'; ch++) {
            string re_str = { ch };
            re_str = regex_replace(s1, regex("_"), re_str);
            regex re(re_str);
            smatch match;

            if (regex_match(s2, match, re)) {
                if (ans == '!') {
                    ans = ch;
                }
                else {
                    ans = '_';
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
