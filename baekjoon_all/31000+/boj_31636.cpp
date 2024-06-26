// Solve 2024-06-05

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
    string s;
    cin >> n >> s;

    bool ans = false;
    int cur = 0;

    for (char c : s) {
        if (c == 'o') {
            if (++cur == 3) {
                ans = true;
                break;
            }
        }
        else {
            cur = 0;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
