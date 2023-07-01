// Solve 2023-07-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int direction = 0;

    for (int i = 0; i < 10; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            direction++;
            if (direction == 4) direction = 0;
        }
        else if (cmd == 2) {
            direction += 2;
            if (direction >= 4) direction -= 4;
        }
        else {
            direction--;
            if (direction == -1) direction = 3;
        }
    }

    if (direction == 0) cout << "N\n";
    else if (direction == 1) cout << "E\n";
    else if (direction == 2) cout << "S\n";
    else cout << "W\n";

    return 0;
}
