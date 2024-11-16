// Solve 2024-11-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

bool sieve[5000001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        if (sieve[i]) continue;

        for (int j = i + i; j <= n; j += i) {
            sieve[j] = true;
        }
    }

    vector<int> primes;

    for (int i = 1; i <= n; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int ans = upper_bound(all(primes), b) - lower_bound(all(primes), a);
        println(ans);
    }

    return 0;
}
