// Solve 2025-02-22

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

void clear_stack(stack<int> &stck) {
    while (!stck.empty()) {
        stck.pop();
    }
}

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    stack<int> stck;
    int ans = 0;

    for (char &c : s) {
        if (c == 's') {
            stck.push(1);
        }
        else if (c == 'k') {
            if (!stck.empty() && stck.top() == 1) {
                stck.top()++;
            }
            else {
                clear_stack(stck);
            }
        }
        else if (c == 'e') {
            if (!stck.empty() && (stck.top() == 2 || stck.top() == 3)) {
                stck.top()++;
            }
            else {
                clear_stack(stck);
            }
        }
        else if (c == 'p') {
            if (!stck.empty() && stck.top() == 4) {
                stck.top()++;
            }
            else {
                clear_stack(stck);
            }
        }
        else {
            clear_stack(stck);
        }

        while (!stck.empty() && stck.top() == 5) {
            ans++;
            stck.pop();

            if (!stck.empty()) {
                stck.top()++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
