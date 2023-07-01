// Solve 2022-06-05
// Update 2023-07-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string line;
        getline(cin, line);
        if (line == ".") break;

        stack<char> stck;
        bool is_vaild = true;

        for (auto ch : line) {
            if (ch == '(' || ch == '[') {
                stck.push(ch);
            }
            else if (ch == ')') {
                if (stck.empty() || stck.top() != '(') {
                    is_vaild = false;
                    break;
                }
                stck.pop();
            }
            else if (ch == ']') {
                if (stck.empty() || stck.top() != '[') {
                    is_vaild = false;
                    break;
                }
                stck.pop();
            }
        }
        if (!stck.empty()) {
            is_vaild = false;
        }

        if (is_vaild) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
