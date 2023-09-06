// Solve 2022-08-26
// Update 2023-09-06

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

    vector<string> vec;

    for (int i = 0, ie = SIZE(s); i < ie; i++) {
        vec.push_back(s.substr(i, ie - i));
    }

    sort(vec.begin(), vec.end());

    for (const string &s : vec) {
        cout << s << '\n';
    }

    return 0;
}
