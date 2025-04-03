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

    int n;
    cin >> n;

    string binary;

    while (n > 0) {
        binary.push_back('0' + n % 2);
        n /= 2;
    }

    int ans = 0;

    for (char &bit : binary) {
        ans = ans * 2 + (bit - '0');
    }

    cout << ans << '\n';

    return 0;
}
