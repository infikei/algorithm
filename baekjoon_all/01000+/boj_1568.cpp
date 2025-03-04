// Solve 2022-10-11
// Update 2025-03-04

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

    int cnt = 0;
    int i = 1;

    while (n > 0) {
        n -= i;
        i++;
        cnt++;

        if (n < i) {
            i = 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}
