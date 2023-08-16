// Solve 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<string> colors(4);

    for (string &s : colors) {
        cin >> s;
    }

    sort(colors.begin(), colors.end());

    colors.erase(unique(colors.begin(), colors.end()), colors.end());

    for (const string &s : colors) {
        for (const string &w : colors) {
            cout << s << ' ' << w << '\n';
        }
    }

    return 0;
}
