// Solve 2025-09-27

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
    int cnt = 0;

    while (size(s) >= 2) {
        if (s.back() == '0') {
            s.pop_back();
        }
        else {
            cnt++;

            while (!s.empty() && s.back() == '1') {
                s.pop_back();
            }

            if (!s.empty()) {
                s.back() = '1';
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
