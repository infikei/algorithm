// Solve 2025-08-22

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

    int k, d;
    cin >> k >> d;
    int complete_books = 0;
    int writing_days = 0;

    while (true) {
        writing_days += k;
        k *= 2;

        if (writing_days > d) break;

        complete_books++;
    }

    cout << complete_books << '\n';
    return 0;
}
