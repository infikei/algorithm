// Solve 2025-05-31

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

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    stack<int> stck;
    stck.push(-1);
    int depth = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth++;
            stck.push(i);
        }
        else {
            depth--;
            stck.pop();

            if (stck.empty()) {
                stck.push(i);
            }
            else {
                max_len = max(max_len, i - stck.top());
            }
        }
    }

    cout << max_len << '\n';

    return 0;
}
