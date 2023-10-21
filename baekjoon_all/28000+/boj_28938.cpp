// Solve 2023-10-20

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

    int pos = 0;

    for (int i = 0; i < n; i++) {
        int dx;
        cin >> dx;

        pos += dx;
    }

    if (pos > 0) cout << "Right\n";
    else if (pos < 0) cout << "Left\n";
    else cout << "Stay\n";

    return 0;
}
