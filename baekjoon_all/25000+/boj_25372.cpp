// Solve 2022-07-26
// Update 2024-03-11

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

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (SIZE(s) >= 6 && SIZE(s) <= 9) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
