// Solve 2026-02-16

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

    int mx = 0;
    int state = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            if (state == 1) {
                state = 2;
            }
            else {
                state = 0;
            }
        }
        else if (s[i] == 'A') {
            if (state == 2) {
                state = 3;
            }
            else {
                state = 0;
            }
        }
        else {
            if (state == 3) {
                mx++;
                state = 0;
            }
            else {
                state = 1;
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
