// Solve 2025-06-01

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

    string a, b;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a += s;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b += s;
    }

    cout << min(stoll(a), stoll(b)) << '\n';

    return 0;
}
