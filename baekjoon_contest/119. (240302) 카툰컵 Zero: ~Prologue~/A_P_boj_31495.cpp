// Solve 2024-03-02

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
    getline(cin, s);

    if (SIZE(s) >= 3 && s[0] == '"' && s.back() == '"') {
        cout << s.substr(1, SIZE(s) - 2) << '\n';
    }
    else {
        cout << "CE\n";
    }

    return 0;
}
