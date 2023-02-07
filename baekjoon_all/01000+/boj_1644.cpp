// Solve 2023-02-07

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int n, ans;
vector<int> primes;

void check_prime() {
    bool is_not_prime[4000001] = { false };
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (is_not_prime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i + i; j <= n; j += i) {
            is_not_prime[j] = true;
        }
    }
}

int main() {
    FASTIO;

    cin >> n;

    check_prime();

    int left = 0, right = 0, sum_left_to_right = 0;
    while (true) {
        if (sum_left_to_right > n) {
            sum_left_to_right -= primes[left];
            left++;
        }
        else if (sum_left_to_right < n) {
            if (right == SIZE(primes)) {
                break;
            }
            sum_left_to_right += primes[right];
            right++;
        }
        else {
            ans++;
            if (right == SIZE(primes)) {
                break;
            }
            sum_left_to_right -= primes[left];
            left++;
            sum_left_to_right += primes[right];
            right++;
        }
    }

    cout << ans << '\n';

    return 0;
}