// Solve 2023-06-26

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

    deque<int> dq;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == 2) {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == 3) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (cmd == 4) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (cmd == 5) {
            cout << SIZE(dq) << '\n';
        }
        else if (cmd == 6) {
            cout << dq.empty() << '\n';
        }
        else if (cmd == 7) {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        else {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}
