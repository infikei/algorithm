// Solve 2022-06-04
// Update 2023-12-20

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
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;

            stck.push(x);
        }
        else if (cmd == "pop") {
            if (stck.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << stck.top() << '\n';
                stck.pop();
            }
        }
        else if (cmd == "size") {
            cout << SIZE(stck) << '\n';
        }
        else if (cmd == "empty") {
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
