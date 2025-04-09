// Solve 2023-05-21
// Update 2025-04-08

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

    int a = 1;
    int b = n;

    while (true) {
        cout << a << ' ';
        a++;

        if (a > b) break;

        cout << b << ' ';
        b--;

        if (a > b) break;
    }

    cout << '\n';

    return 0;
}
