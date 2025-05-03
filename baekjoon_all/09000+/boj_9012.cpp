// Solve 2022-06-05
// Update 2025-05-03

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

bool is_valid_parentheses(string &parentheses) {
    int depth = 0;

    for (char &par : parentheses) {
        if (par == '(') {
            depth++;
        }
        else {
            depth--;

            if (depth < 0) return false;
        }
    }

    return depth == 0;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string parentheses;
        cin >> parentheses;

        cout << (is_valid_parentheses(parentheses) ? "YES" : "NO") << '\n';
    }

    return 0;
}
