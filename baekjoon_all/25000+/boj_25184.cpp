// Solve 2025-04-10

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

    int a = n / 2 + 1;
    int b = 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << a << ' ';
            a++;
        }
        else {
            cout << b << ' ';
            b++;
        }
    }

    cout << '\n';

    return 0;
}
