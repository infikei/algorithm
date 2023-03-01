// Solve 2022-06-06
// Update 2023-03-01

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    deque<int> dq;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << SIZE(dq) << '\n';
        }
        else if (cmd == "empty") {
            cout << dq.empty() << '\n';
        }
        else if (cmd == "front") {
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