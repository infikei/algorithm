// Solve 2023-08-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    bool incr = true, decr = true, same = true;

    int prev;
    cin >> prev;

    for (int i = 1; i < 4; i++) {
        int x;
        cin >> x;

        if (prev < x) {
            decr = false;
            same = false;
        }
        else if (prev > x) {
            incr = false;
            same = false;
        }
        else {
            incr = false;
            decr = false;
        }

        prev = x;
    }

    if (incr) {
        cout << "Fish Rising\n";
    }
    else if (decr) {
        cout << "Fish Diving\n";
    }
    else if (same) {
        cout << "Fish At Constant Depth\n";
    }
    else {
        cout << "No Fish\n";
    }

    return 0;
}
