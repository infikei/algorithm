// Solve 2025-11-10

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

    int n;
    cin >> n;
    string s;

    while (n != 0) {
        if (n % 3 == 0) {
            s.push_back('0');
            n /= 3;
        }
        else if ((n - 1) % 3 == 0) {
            s.push_back('1');
            n = (n - 1) / 3;
        }
        else {
            s.push_back('T');
            n = (n + 1) / 3;
        }
    }

    if (s.empty()) {
        s.push_back('0');
    }

    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}
