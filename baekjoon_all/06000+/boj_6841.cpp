// Solve 2023-01-09
// Update 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    unordered_map<string, string> hs = {
        { "CU", "see you" },
        { ":-)", "I’m happy" },
        { ":-(", "I’m unhappy" },
        { ";-)", "wink" },
        { ":-P", "stick out my tongue" },
        { "(~.~)", "sleepy" },
        { "TA", "totally awesome" },
        { "CCC", "Canadian Computing Competition" },
        { "CUZ", "because" },
        { "TY", "thank-you" },
        { "YW", "you’re welcome" },
        { "TTYL", "talk to you later" }
    };

    while (true) {
        string form;
        cin >> form;

        if (hs.find(form) != hs.end()) {
            cout << hs[form] << '\n';
        }
        else {
            cout << form << '\n';
        }

        if (form == "TTYL") break;
    }

    return 0;
}
