// Solve 2023-10-28
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    char ch = '*';

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char x;
            cin >> x;

            if (x == 'w' || x == 'b' || x == 'g') {
                ch = x;
            }
        }
    }

    if (ch == 'w') {
        cout << "chunbae\n";
    }
    else if (ch == 'b') {
        cout << "nabi\n";
    }
    else {
        cout << "yeongcheol\n";
    }

    return 0;
}
