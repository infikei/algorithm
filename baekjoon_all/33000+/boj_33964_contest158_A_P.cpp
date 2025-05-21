// Solve 2025-05-17

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

int get_repunit(int k) {
    int res = 0;

    while (k-- > 0) {
        res = res * 10 + 1;
    }

    return res;
}

int main() {
    FASTIO;

    int x, y;
    cin >> x >> y;

    cout << get_repunit(x) + get_repunit(y) << '\n';

    return 0;
}
