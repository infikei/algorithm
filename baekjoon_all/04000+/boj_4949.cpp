// Solve 2022-06-05
// Update 2025-04-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool check_vaild_parentheses(string &s) {
    stack<char> stck;

    for (char &c : s) {
        switch (c) {
            case '(':
            case '[':
                stck.push(c);
                break;

            case ')':
                if (stck.empty() || stck.top() != '(') return false;

                stck.pop();
                break;

            case ']':
                if (stck.empty() || stck.top() != '[') return false;

                stck.pop();
                break;
        }
    }

    return stck.empty();
}

int main() {
    FASTIO;

    while (true) {
        string line;
        getline(cin, line);

        if (line == ".") break;

        if (check_vaild_parentheses(line)) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }

    return 0;
}
