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

    stack<int> stck;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x;
            cin >> x;
            stck.push(x);
        }
        else if (cmd == 2) {
            if (stck.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stck.top() << '\n';
                stck.pop();
            }
        }
        else if (cmd == 3) {
            cout << SIZE(stck) << '\n';
        }
        else if (cmd == 4) {
            cout << stck.empty() << '\n';
        }
        else {
            if (stck.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stck.top() << '\n';
            }
        }
    }

    return 0;
}
