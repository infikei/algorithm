// Solve 2025-04-06

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

    int q;
    cin >> q;

    list<int> li;

    while (q-- > 0) {
        int cmd, x, t;
        cin >> cmd >> x;

        if (cmd == 1) {
            if (x == 1) {
                li.sort();
            }
            else {
                li.sort();
                li.reverse();
            }
        }
        else {
            cin >> t;

            if (x == 0) {
                li.push_front(t);
            }
            else if (x == li.size()) {
                li.push_back(t);
            }
            else {
                list<int>::iterator it = li.begin();

                for (int i = 0; i < x; i++) it++;

                li.insert(it, t);
            }
        }
    }

    cout << li.size() << '\n';

    for (auto it = li.begin(); it != li.end(); it++) {
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}
