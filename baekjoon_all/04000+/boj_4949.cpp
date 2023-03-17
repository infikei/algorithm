// Solve 2022-06-05
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

int main() {
    FASTIO;

    while (true) {
        string line;
        getline(cin, line);
        if (line == ".") {
            break;
        }

        stack<char> stck;
        bool check = true;

        for (auto ch : line) {
            if (ch == '(' || ch == '[') {
                stck.push(ch);
            }
            else if (ch == ')') {
                if (stck.empty() || stck.top() != '(') {
                    check = false;
                    break;
                }
                stck.pop();
            }
            else if (ch == ']') {
                if (stck.empty() || stck.top() != '[') {
                    check = false;
                    break;
                }
                stck.pop();
            }
        }
        if (!stck.empty()) {
            check = false;
        }

        if (check) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
