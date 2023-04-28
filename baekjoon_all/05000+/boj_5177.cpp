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

    int k;
    cin >> k;
    cin.ignore();

    string s[2];
    regex re1("[ ]*([^a-zA-Z0-9 ])[ ]*");
    regex re2("[ ]+");
    regex re3("^ | $");

    for (int ki = 1; ki <= k; ki++) {
        getline(cin, s[0]);
        getline(cin, s[1]);

        for (int s_idx = 0; s_idx < 2; s_idx++) {
            string si = s[s_idx];

            si = regex_replace(si, re1, "$1");
            si = regex_replace(si, re2, " ");
            si = regex_replace(si, re3, "");

            for (int i = 0, i_end = SIZE(si); i < i_end; i++) {
                if (isupper(si[i])) {
                    si[i] = si[i] - 'A' + 'a';
                }
                else if (si[i] == '[' || si[i] == '{') {
                    si[i] = '(';
                }
                else if (si[i] == ']' || si[i] == '}') {
                    si[i] = ')';
                }
                else if (si[i] == ';') {
                    si[i] = ',';
                }
            }

            s[s_idx] = si;
        }

        cout << "Data Set " << ki;
        if (s[0] == s[1]) {
            cout << ": equal\n";
        }
        else {
            cout << ": not equal\n";
        }
        if (ki != k) {
            cout << '\n';
        }
    }

    return 0;
}
