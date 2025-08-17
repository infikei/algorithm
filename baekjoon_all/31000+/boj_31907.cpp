// Solve 2025-08-16

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

string gist[3] = {"G...", ".I.T", "..S."};

int main() {
    FASTIO;

    int k;
    cin >> k;

    for (int x = 0; x < 3; x++) {
        string new_row;

        for (int y = 0; y < 4; y++) {
            for (int j = 0; j < k; j++) {
                new_row.push_back(gist[x][y]);
            }
        }

        for (int i = 0; i < k; i++) {
            cout << new_row << '\n';
        }
    }

    return 0;
}
