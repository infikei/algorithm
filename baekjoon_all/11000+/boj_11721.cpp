// Solve 2023-02-11
// Update 2023-08-03

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

    while (true) {
        if (SIZE(s) <= 10) {
            cout << s << '\n';
            break;
        }

        cout << s.substr(0, 10) << '\n';
        s = s.substr(10);
    }

    return 0;
}
