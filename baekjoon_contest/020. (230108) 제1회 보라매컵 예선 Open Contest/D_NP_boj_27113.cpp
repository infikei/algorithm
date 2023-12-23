// Solve 2023-01-09
// Update 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int new_pos(int pos, int s, int e) {
    if (pos >= s && pos <= e) return e + 1;
    return pos;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int pos = 1;

    for (int row = 1; row < n; row++) {
        int x;
        cin >> x;

        int c[2];
        char d[2];

        for (int i = 0; i < x; i++) {
            cin >> c[i] >> d[i];
        }

        if (x == 1) {
            if (d[0] == 'L') pos = new_pos(pos, 1, c[0]);
            else pos = new_pos(pos, c[0], m);
        }
        else if (x == 2) {
            if (d[0] == 'L') pos = new_pos(pos, 1, c[0]);
            else pos = new_pos(pos, c[0], c[1]);

            if (d[1] == 'L') pos = new_pos(pos, c[0], c[1]);
            else pos = new_pos(pos, c[1], m);
        }
    }

    cout << (pos <= m ? "YES" : "NO") << '\n';

    return 0;
}
