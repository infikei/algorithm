// Solve 2022-11-17
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

    int n;
    cin >> n;

    vector<string> vec(n);

    for (string &s : vec) {
        cin >> s;
    }

    int k;
    cin >> k;

    if (k == 2) {
        for (string &s : vec) {
            reverse(s.begin(), s.end());
        }
    }
    else if (k == 3) {
        reverse(vec.begin(), vec.end());
    }

    for (const string &s : vec) {
        cout << s << '\n';
    }

    return 0;
}
