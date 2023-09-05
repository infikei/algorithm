// Solve 2022-06-03
// Update 2023-09-05

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

    unordered_set<string> hs;

    for (int i = 0, ie = SIZE(s); i < ie; i++) {
        string w;

        for (int j = i, je = SIZE(s); j < je; j++) {
            w.push_back(s[j]);
            hs.insert(w);
        }
    }

    cout << SIZE(hs) << '\n';

    return 0;
}
