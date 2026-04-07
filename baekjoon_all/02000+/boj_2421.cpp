// Solve 2026-04-03

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

int memo[1000][1000];
bool sieve[1000000];

void create_sieve() {
    for (int i = 2; i * i < 1000000; i++) {
        if (sieve[i]) continue;

        for (int j = i * i; j < 1000000; j += i) {
            sieve[j] = true;
        }
    }
}

int main() {
    FASTIO;

    create_sieve();

    int n;
    cin >> n;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            memo[x][y] = max(memo[x][y - 1], memo[x - 1][y]);

            int cur = stoi(to_string(x) + to_string(y));

            if (!sieve[cur]) {
                memo[x][y]++;
            }
        }
    }

    cout << memo[n][n] - 1 << '\n';
    return 0;
}
