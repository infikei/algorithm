// Solve 2025-11-12

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

bool sieve[1000];
vector<int> primes;
int arr[100];
int cnt[100];

void create_sieve() {
    memset(sieve, true, sizeof sieve);

    for (int i = 2; i * i < 1000; i++) {
        if (sieve[i]) {
            primes.push_back(i);

            for (int j = i * i; j < 1000; j += i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = primes.back(); i < 1000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    FASTIO;

    create_sieve();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 1;
    int ans2 = 0;

    for (int p : primes) {
        memset(cnt, 0, sizeof cnt);
        int cnt_sum = 0;

        for (int i = 0; i < n; i++) {
            while (arr[i] % p == 0) {
                arr[i] /= p;
                cnt[i]++;
            }

            cnt_sum += cnt[i];
        }

        int cnt_avg = cnt_sum / n;

        for (int i = 0; i < n; i++) {
            if (cnt[i] < cnt_avg) {
                ans2 += cnt_avg - cnt[i];
            }
        }

        while (cnt_avg-- > 0) {
            ans *= p;
        }
    }

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 1) {
            mp[arr[i]]++;
        }
    }

    for (auto [p, v] : mp) {
        if (v == n) {
            ans *= p;
        }
    }

    cout << ans << ' ' << ans2 << '\n';
    return 0;
}
