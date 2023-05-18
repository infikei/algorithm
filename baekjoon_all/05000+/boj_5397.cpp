// Solve 2022-08-19
// Update 2023-05-18

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

string input, ans;
stack<char> stck_left, stck_right;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        cin >> input;

        for (auto ch : input) {
            if (ch == '<') {
                if (!stck_left.empty()) {
                    stck_right.push(stck_left.top());
                    stck_left.pop();
                }
            }
            else if (ch == '>') {
                if (!stck_right.empty()) {
                    stck_left.push(stck_right.top());
                    stck_right.pop();
                }
            }
            else if (ch == '-') {
                if (!stck_left.empty()) {
                    stck_left.pop();
                }
            }
            else {
                stck_left.push(ch);
            }
        }

        while (!stck_left.empty()) {
            stck_right.push(stck_left.top());
            stck_left.pop();
        }

        ans = "";

        while (!stck_right.empty()) {
            ans.push_back(stck_right.top());
            stck_right.pop();
        }
        cout << ans << '\n';
    }

    return 0;
}
