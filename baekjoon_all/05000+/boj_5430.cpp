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

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string cmds, nums;
        int n;
        cin >> cmds >> n >> nums;

        deque<int> dq;
        string tmp = "";
        for (char ch : nums) {
            if (ch >= '0' && ch <= '9') {
                tmp += ch;
            }
            else {
                if (!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        bool error = false, reversed = false;
        for (char cmd : cmds) {
            if (cmd == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (reversed) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
            else {
                reversed = !reversed;
            }
        }

        if (error) {
            cout << "error\n";
        }
        else if (dq.empty()) {
            cout << "[]\n";
        }
        else if (reversed) {
            cout << '[' << dq.back();
            for (int i = SIZE(dq) - 2; i >= 0; i--) {
                cout << ',' << dq[i];
            }
            cout << "]\n";
        }
        else {
            cout << '[' << dq[0];
            int i_end = SIZE(dq);
            for (int i = 1; i < i_end; i++) {
                cout << ',' << dq[i];
            }
            cout << "]\n";
        }
    }

    return 0;
}