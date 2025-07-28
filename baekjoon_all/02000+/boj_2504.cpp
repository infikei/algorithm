// Solve 2022-08-10
// Update 2025-07-27

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pci = pair<char, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int get_val_of_parentheses(string& par) {
    stack<pci> stck;

    for (char c : par) {
        if (c == ')') {
            if (!stck.empty() && stck.top().first == '(') {
                stck.top() = {'*', 2};
                continue;
            }

            int inner_val = 0;

            while (!stck.empty() && stck.top().first == '*') {
                inner_val += stck.top().second;
                stck.pop();
            }

            if (stck.empty() || stck.top().first != '(') {
                return 0;
            }

            stck.top() = {'*', inner_val * 2};
        }
        else if (c == ']') {
            if (!stck.empty() && stck.top().first == '[') {
                stck.top() = {'*', 3};
                continue;
            }

            int inner_val = 0;

            while (!stck.empty() && stck.top().first == '*') {
                inner_val += stck.top().second;
                stck.pop();
            }

            if (stck.empty() || stck.top().first != '[') {
                return 0;
            }

            stck.top() = {'*', inner_val * 3};
        }
        else {
            stck.emplace(c, 0);
        }
    }

    int ret = 0;

    while (!stck.empty() && stck.top().first == '*') {
        ret += stck.top().second;
        stck.pop();
    }

    return stck.empty() ? ret : 0;
}

int main() {
    FASTIO;

    string par;
    cin >> par;
    cout << get_val_of_parentheses(par) << '\n';
    return 0;
}
