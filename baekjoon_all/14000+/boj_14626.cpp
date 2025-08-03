// Solve 2025-07-31

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    string isbn;
    cin >> isbn;

    int sum_isbn = 0;
    int idx_of_deleted_digit = 0;

    for (int i = 0; i < size(isbn); i++) {
        if (isbn[i] == '*') {
            idx_of_deleted_digit = i;
            continue;
        }

        sum_isbn += (isbn[i] - '0') * (i % 2 == 0 ? 1 : 3);
    }

    for (int i = 0; i <= 9; i++) {
        int x = sum_isbn + i * (idx_of_deleted_digit % 2 == 0 ? 1 : 3);

        if (x % 10 == 0) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
