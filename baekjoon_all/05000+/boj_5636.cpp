// Solve 2025-06-29

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

bool sieve[100000];

void init_sieve() {
    memset(sieve, 1, sizeof sieve);
    sieve[0] = sieve[1] = 0;

    for (int i = 2; i < 100000; i++) {
        if (!sieve[i]) continue;

        for (int j = i * 2; j < 100000; j += i) {
            sieve[j] = false;
        }
    }
}

bool input(string& s) {
    cin >> s;
    return (s != "0");
}

void pro(string& s) {
    int res = -1;

    for (int len = 1; len <= 5; len++) {
        for (int i = len - 1; i < size(s); i++) {
            int sub_num = stoi(s.substr(i - len + 1, len));

            if (sieve[sub_num]) {
                res = max(res, sub_num);
            }
        }
    }

    cout << res << '\n';
}

int main() {
    FASTIO;

    init_sieve();
    string s;

    while (input(s)) {
        pro(s);
    }

    return 0;
}
