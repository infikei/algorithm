// Solve 2025-03-22

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int having[4];

    for (int i = 0; i < 4; i++) {
        cin >> having[i];
    }

    int to_need[4];

    for (int i = 0; i < 4; i++) {
        cin >> to_need[i];
    }

    int made_cnt = 0;

    int q;
    cin >> q;

    while (q-- > 0) {
        int cmd, x;
        cin >> cmd >> x;

        if (cmd == 1) {
            bool can_make = true;

            for (int i = 0; i < 4; i++) {
                if (x * to_need[i] > having[i]) {
                    can_make = false;
                    break;
                }
            }

            if (can_make) {
                made_cnt += x;
                cout << made_cnt << '\n';

                for (int i = 0; i < 4; i++) {
                    having[i] -= x * to_need[i];
                }
            }
            else {
                cout << "Hello, siumii" << '\n';
            }
        }
        else {
            having[cmd - 2] += x;
            cout << having[cmd - 2] << '\n';
        }
    }

    return 0;
}
