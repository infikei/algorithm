// Solve 2023-08-01

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

    int idx = s.find('x');

    if (idx == string::npos) {
        cout << 0 << '\n';
    }
    else {
        string s0 = s.substr(0, idx);

        if (s0 == "") cout << 1 << '\n';
        else if (s0 == "-") cout << -1 << '\n';
        else cout << stoi(s0) << '\n';
    }

    return 0;
}
