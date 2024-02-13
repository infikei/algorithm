// Solve 2022-08-06
// Update 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string infix;
    cin >> infix;

    string postfix;
    stack<char> stck;

    for (char cur : infix) {
        if (cur == '(') {
            stck.push(cur);
        }
        else if (cur == ')') {
            while (stck.top() != '(') {
                postfix.push_back(stck.top());
                stck.pop();
            }

            stck.pop();
        }
        else if (cur == '+' || cur == '-') {
            while (!stck.empty() && stck.top() != '(') {
                postfix.push_back(stck.top());
                stck.pop();
            }

            stck.push(cur);
        }
        else if (cur == '*' || cur == '/') {
            while (!stck.empty() && stck.top() != '(' && stck.top() != '+' && stck.top() != '-') {
                postfix.push_back(stck.top());
                stck.pop();
            }

            stck.push(cur);
        } else {
            postfix.push_back(cur);
        }
    }

    while (!stck.empty()) {
        postfix.push_back(stck.top());
        stck.pop();
    }

    cout << postfix << '\n';

    return 0;
}
