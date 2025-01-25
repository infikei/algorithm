// Solve 2025-01-25

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

bool sieve[2301];
vector<int> primes;

void create_sieve() {
    sieve[0] = sieve[1] = true;

    for (int i = 2; i <= 2300; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (int j = i * i; j <= 2300; j += i) {
            sieve[j] = true;
        }
    }
}

vector<int> get_prime_divisors(int k) {
    vector<int> prime_divisors;

    for (int &p : primes) {
        // k가 p 이상인 경우에만 나머지 연산을 수행한다.
        while (k >= p && k % p == 0) {
            prime_divisors.push_back(p);
            k /= p;
        }

        // k가 1이면 더 이상 나눌 수 있는 소수가 없으므로 즉시 반환한다.
        if (k == 1) return prime_divisors;
    }

    if (k > 1) {
        prime_divisors.push_back(k);
    }

    return prime_divisors;
}

int main() {
    FASTIO;

    // k가 5,000,000 이하인 경우만 주어지므로 2,300 이하의 소수만 구해도 충분하다.
    // (2,300보다 큰 소수들로만 이루어진 합성수는 5,000,000을 넘기 때문)
    create_sieve();

    int n;
    cin >> n;

    while (n-- > 0) {
        int k;
        cin >> k;

        vector<int> prime_divisors = get_prime_divisors(k);

        for (int &p : prime_divisors) {
            printw(p);
        }

        cout << '\n';
    }

    return 0;
}
