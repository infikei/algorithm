// Solve 2023-02-19
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

    int n;
    cin >> n;

    deque<pair<char, int>> dque;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            char c;
            cin >> c;
            dque.emplace_back(c, SIZE(dque));
        }
        else if (cmd == 2) {
            char c;
            cin >> c;
            dque.emplace_front(c, SIZE(dque));
        }
        else {
            if (dque.empty()) continue;

            if (dque.front().second < dque.back().second) {
                dque.pop_back();
            }
            else {
                dque.pop_front();
            }
        }
    }

    if (dque.empty()) {
        cout << 0 << '\n';
    }
    else {
        for (auto p : dque) {
            cout << p.first;
        }

        cout << '\n';
    }

    return 0;
}
