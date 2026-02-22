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

int n, m;
int nums[200001];
int par[200000];
vector<pii> queries;
bool sieve[500000];
vector<int> primes;

void create_sieve() {
    for (int i = 2; i * i < 500000; i++) {
        if (sieve[i]) continue;

        for (int j = i * i; j < 500000; j += i) {
            sieve[i] = true;
        }

        primes.push_back(i);
    }
}

ll get_gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

pll add_frac(pll p, pll q) {
    ll child = p.first * q.second + q.first * p.second;
    ll parent = p.second * q.second;
    ll gcd = get_gcd(child, parent);
    return pll(child / gcd, parent / gcd);
}

void convert(int idx) {
    int val = nums[idx];
    int p_sum = 0;
    int p_cnt = 0;

    for (int p : primes) {
        if (val % p == 0) {
            val /= p;
            p_sum += p;
            p_cnt++;

            while (val % p == 0) {
                val /= p;
            }
        }
    }

    if (val > 1) {
        p_sum += val;
        p_cnt++;
    }

    nums[idx] = p_sum;
    par[idx] = p_cnt;
}

int main() {
    FASTIO;

    create_sieve();

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        par[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        queries.emplace_back(u, v);
    }

    sort(queries.begin(), queries.end());
    int last = 0;

    for (auto [u, v] : queries) {
        u = max(u, last + 1);

        for (int i = u; i <= v; i++) {
            convert(i);
        }

        last = max(last, v);
    }

    pll ans(0, 1);

    for (int i = 1; i <= n; i++) {
        ans = add_frac(ans, pll(nums[i], par[i]));
    }

    SETP(12);
    cout << ans.first / (double) ans.second << '\n';
    return 0;
}
