// Solve 2025-03-02

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
    string magnet;
    cin >> n >> magnet;

    bool connected = true;

    for (int i = 1; i < SIZE(magnet); i++) {
        if (magnet[i - 1]  == magnet[i]) {
            connected = false;
            break;
        }
    }

    cout << (connected ? "Yes" : "No") << '\n';

    return 0;
}
