// Solve 2024-05-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    if (a == 3 || a == 4) {
        a = 1;
    }

    if (b == 3 || b == 4) {
        b = 1;
    }

    if (a == b) {
        cout << "=\n";
    }
    else if (a == 1) {
        cout << "<\n";
    }
    else if (b == 1) {
        cout << ">\n";
    }
    else if (a == 0 && b == 5 || a == 2 && b == 0 || a == 5 && b == 2) {
        cout << "<\n";
    }
    else {
        cout << ">\n";
    }

    return 0;
}
