#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, m;

int new_pos(int pos, int s, int e) {
    if (pos >= s && pos <= e) return e + 1;
    return pos;
}

int main() {
    fastio;

    cin >> n >> m;

    int pos = 1;
    for (int row = 1; row < n; row++) {
        int x, c[2];
        char d[2];
        cin >> x;
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

    if (pos <= m) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}