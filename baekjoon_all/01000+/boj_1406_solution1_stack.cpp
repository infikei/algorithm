// Solve 2022-09-10
// Update 2023-03-17

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

stack<char> stck_left, stck_right;

int main() {
    FASTIO;

    string s;
    cin >> s;
    for (auto ch : s) {
        stck_left.push(ch);
    }

    int m;
    cin >> m;

    for (int mi = 0; mi < m; mi++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!stck_left.empty()) {
                stck_right.push(stck_left.top());
                stck_left.pop();
            }
        }
        else if (cmd == 'D') {
            if (!stck_right.empty()) {
                stck_left.push(stck_right.top());
                stck_right.pop();
            }
        }
        else if (cmd == 'B') {
            if (!stck_left.empty()) {
                stck_left.pop();
            }
        }
        else {
            char ch;
            cin >> ch;
            stck_left.push(ch);
        }
    }

    while (!stck_left.empty()) {
        stck_right.push(stck_left.top());
        stck_left.pop();
    }
    while (!stck_right.empty()) {
        cout << stck_right.top();
        stck_right.pop();
    }
    cout << '\n';

    return 0;
}
