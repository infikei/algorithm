// Solve 2022-08-19
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

    vector<int> cmds(n);

    for (int &cmd : cmds) {
        cin >> cmd;
    }

    deque<int> dque;

    for (int i = 1; i <= n; i++) {
        dque.push_back(i);
    }

    stack<int> stck;

    for (int &cmd : cmds) {
        if (cmd == 1) {
            stck.push(dque.front());
            dque.pop_front();
        }
        else if (cmd == 2) {
            int a = dque.front();
            dque.pop_front();
            stck.push(dque.front());
            dque.pop_front();
            dque.push_front(a);
        }
        else {
            stck.push(dque.back());
            dque.pop_back();
        }
    }

    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ans[stck.top()] = i;
        stck.pop();
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
