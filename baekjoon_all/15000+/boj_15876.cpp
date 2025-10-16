// Solve 2025-10-14

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

string s;

void build_s() {
    s.push_back('0');

    for (int i = 0; i <= 100; i++) {
        string b;
        int x = i;

        while (x > 0) {
            b.push_back('0' + (x & 1));
            x >>= 1;
        }

        while (!b.empty()) {
            s.push_back(b.back());
            b.pop_back();
        }
    }
}

int main() {
    FASTIO;

    build_s();
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 5; i++) {
        cout << s[(k - 1) + i * n] << ' ';
    }

    cout << '\n';
    return 0;
}
