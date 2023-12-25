// Solve 2023-09-10
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int y, x;
    cin >> y >> x;

    vector<string> vec(y);

    for (string &s : vec) {
        cin >> s;
    }

    bool ans = false;

    if (x % 2 == 0) {
        int xs = x / 2 - 2;

        for (string &s : vec) {
            if (s[xs] == 'X' && s[xs + 1] == 'X' && s[xs + 2] == 'X' && s[xs + 3] == 'X') {
                s[xs] = 'W';
                s[xs + 1] = 'Y';
                s[xs + 2] = 'Y';
                s[xs + 3] = 'W';

                ans = true;
                break;
            }
        }
    }
    else {
        int xs = x / 2 - 1;

        for (string &s : vec) {
            if (s[xs] == 'X' && s[xs + 1] == 'X' && s[xs + 2] == 'X') {
                s[xs] = 'W';
                s[xs + 1] = 'Y';
                s[xs + 2] = 'W';

                ans = true;
                break;
            }
        }
    }

    if (ans) {
        cout << "YES\n";

        for (string &s : vec) {
            for (char &c : s) {
                if (c == 'X') c = 'B';
            }

            cout << s << '\n';
        }
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
