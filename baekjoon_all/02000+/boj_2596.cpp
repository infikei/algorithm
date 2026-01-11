// Solve 2026-01-11

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

int key[8] = {0b000000, 0b111100, 0b110010, 0b001110, 0b011001, 0b100101, 0b101011, 0b010111};
int b[10];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            char c;
            cin >> c;

            if (c == '1') {
                b[i] |= (1 << j);
            }
        }
    }

    string ans;

    for (int i = 0; i < n; i++) {
        char exact = '.';

        for (int j = 0; j < 8; j++) {
            int diff = __builtin_popcount(b[i] ^ key[j]);

            if (diff <= 1) {
                exact = 'A' + j;
                break;
            }
        }

        if (exact != '.') {
            ans.push_back(exact);
        }
        else {
            cout << (i + 1) << '\n';
            return 0;
        }
    }

    cout << ans << '\n';
    return 0;
}
