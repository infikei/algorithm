// Solve 2023-01-08
// Update 2025-04-06

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

    if (n % 2 == 0) {
        cout << "I LOVE CBNU" << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << '*';
    }

    cout << '\n';

    for (int i = 0, ie = n / 2 + 1; i < ie; i++) {
        for (int j = 0, je = ie - 1 - i; j < je; j++) {
            cout << ' ';
        }

        cout << '*';

        if (i > 0) {
            for (int j = 0, je = i * 2 - 1; j < je; j++) {
                cout << ' ';
            }

            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}
