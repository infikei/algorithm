// Solve 2023-02-07
// Update 2025-02-21

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool sieve[4000000];
vector<int> primes;

void find_primes() {
    for (int i = 2; i < 4000000; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (int j = i * 2; j < 4000000; j += i) {
            sieve[j] = true;
        }
    }
}

int main() {
    FASTIO;

    find_primes();

    int n;
    cin >> n;

    int left = 0;
    int right = 0;
    int cur_sum = 0;
    int ans = 0;

    while (true) {
        if (cur_sum > n) {
            cur_sum -= primes[left];
            left++;
        }
        else if (cur_sum < n) {
            if (right == SIZE(primes)) break;

            cur_sum += primes[right];
            right++;
        }
        else {
            ans++;

            if (right == SIZE(primes)) break;

            cur_sum += primes[right] - primes[left];
            left++;
            right++;
        }
    }

    cout << ans << '\n';

    return 0;
}
