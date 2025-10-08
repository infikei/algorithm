// Solve 2025-10-08

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
    string s;
    cin >> n >> s;
    ll cnt[4] = {0};

    for (char c : s) {
        if (c == 'D') {
            cnt[0]++;
        }
        else if (c == 'K') {
            cnt[1] += cnt[0];
        }
        else if (c == 'S') {
            cnt[2] += cnt[1];
        }
        else if (c == 'H') {
            cnt[3] += cnt[2];
        }
    }

    cout << cnt[3] << '\n';
    return 0;
}
