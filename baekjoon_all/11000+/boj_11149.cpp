// Solve 2025-04-03

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

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string s;
        string ans;

        while (getline(ss, s, ' ')) {
            int d = 0;

            for (char &c : s) {
                d += c - 'a';
            }

            d %= 27;
            ans.push_back(d == 26 ? ' ' : 'a' + d);
        }

        cout << ans << '\n';
    }

    return 0;
}
