// Solve 2023-06-26
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

int main() {
    FASTIO;

    int n;
    cin >> n;

    stack<int> stck;

    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;

        switch (cmd) {
            case 1:
                int x;
                cin >> x;
                stck.push(x);
                break;

            case 2:
                if (stck.empty()) {
                    cout << -1 << '\n';
                    break;
                }

                cout << stck.top() << '\n';
                stck.pop();
                break;

            case 3:
                cout << stck.size() << '\n';
                break;

            case 4:
                cout << stck.empty() << '\n';
                break;

            case 5:
                if (stck.empty()) {
                    cout << -1 << '\n';
                    break;
                }

                cout << stck.top() << '\n';
                break;
        }
    }

    return 0;
}
