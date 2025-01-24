// Solve 2025-01-24

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
using lll = __int128;
using lld = __float128;
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
using lll = long long;
using lld = long double;
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

ll mod_mul(ll a, ll b, ll mod) {
    a %= mod;
    b %= mod;
    ll res = 0;

    while (b > 0) {
        if (b & 1) {
            res = (res + a) % mod;
        }

        a = (a << 1) % mod;
        b >>= 1;
    }

    return res;
}

ll mod_pow(ll a, ll p, ll mod) {
    a %= mod;
    ll res = 1;

    while (p > 0) {
        if (p & 1) {
            res = mod_mul(res, a, mod);
        }

        a = mod_mul(a, a, mod);
        p >>= 1;
    }

    return res;
}

ll get_gcd(ll a, ll b) {
    if (b == 0) return a;

    return get_gcd(b, a % b);
}

bool is_probable_prime_with_miller_rabin(ll n, ll a) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    // 이제 n이 홀수임이 보장된다.
    // 따라서 짝수인 n - 1을 2^s * d의 형태로 변환한다. (s >= 1, d는 홀수)
    ll d = n - 1;
    int s = 0;

    while (d % 2 == 0) {
        d >>= 1;
        s++;
    }

    // a^d mod n이 1 또는 -1이면 소수일 가능성이 높다.
    ll a_pow = mod_pow(a, d, n);

    if (a_pow == 1 || a_pow == n - 1) {
        return true;
    }

    // 0 <= r < s인 어떤 r에 대해 a^(2^r * d) mod n이 -1이면 소수일 가능성이 높다.
    for (int r = 1; r < s; r++) {
        a_pow = mod_mul(a_pow, a_pow, n);

        if (a_pow == n - 1) {
            return true;
        }
    }

    // 위의 조건이 모두 성립하지 않으면 합성수이다.
    return false;
}

bool is_prime_with_miller_rabin(ll n) {
    if (n <= 1) return false; // 1 이하의 정수는 소수가 아니다.
    if (n == 2) return true; // 2는 소수이다.
    if (n % 2 == 0) return false; // 2를 제외한 짝수는 합성수이다.

    // 32비트 정수 범위에서는 2, 7, 61에 대해서 테스트를 모두 통과하면 소수이고,
    // 64비트 정수 범위에서는 37 이하의 모든 소수에 대해서 테스트를 모두 통과하면 소수이다.
    ll a_list[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

    for (ll a : a_list) {
        if (a >= n - 1) return true; // 밀러-라빈 테스트에서 a는 2 <= a < n-1을 만족해야 한다.
        if (n % a == 0) return false; // n의 약수를 발견하면 합성수로 판정한다.

        // 밀러-라빈 테스트를 통과하지 못하면 합성수로 판정한다.
        if (!is_probable_prime_with_miller_rabin(n, a)) {
            return false;
        }
    }

    // 주어진 모든 a에 대해 밀러-라빈 테스트를 통과하면 소수로 판정한다.
    return true;
}

ll find_prime_divisor_with_pollard_rho(ll n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2;
    if (is_prime_with_miller_rabin(n)) return n;

    // g(x) = (x^2 + c) mod n으로 정의하고, h(x) = g(g(x))로 정의한다.
    // 수열 x는 x0,      x1 = g(x0), x2 = g(x1), ...로 정의하고,
    // 수열 y는 y0 = x0, y1 = h(y0), y2 = h(y1), ...로 정의한다.

    // 다항식 계산에서 필요한 상수항 c는 1 이상 n-1 이하의 임의의 값으로 정한다.
    ll c = rand() % (n - 1) + 1;
    // 수열 x와 y의 첫째 항은 2 이상 n-1 이하의 임의의 값으로 정한다.
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll gcd = 1;

    // 1보다 크고 n보다 작은 n의 약수를 구할 때까지 반복한다.
    while (gcd == 1) {
        // x = g(x)를 계산한다.
        x = (mod_mul(x, x, n) + c) % n;

        // y = h(y)를 계산한다.
        y = (mod_mul(y, y, n) + c) % n;
        y = (mod_mul(y, y, n) + c) % n;

        // 두 항의 차이와 n의 최대공약수 gcd를 구한다.
        gcd = get_gcd(abs(x - y), n);

        // gcd가 n인 경우, 상수항 c를 다른 값으로 정해서 처음부터 다시 진행해야 하므로
        // 새로운 함수를 호출하여 진행한다.
        if (gcd == n) return find_prime_divisor_with_pollard_rho(n);

        // gcd가 1과 n이 모두 아닌 경우, gcd는 1보다 큰 n의 약수이므로 반복을 종료한다.
    }

    // gcd가 소수인 경우 gcd를 반환한다.
    if (is_prime_with_miller_rabin(gcd)) return gcd;

    // gcd가 소수가 아닌 경우, gcd의 약수를 찾아서 반환한다.
    return find_prime_divisor_with_pollard_rho(gcd);
}

vector<ll> get_prime_divisors_with_pollard_rho(ll n) {
    vector<ll> prime_divisors;

    while (n > 1) {
        ll p = find_prime_divisor_with_pollard_rho(n);
        n /= p;
        prime_divisors.push_back(p);
    }

    sort(all(prime_divisors));

    return prime_divisors;
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    vector<ll> prime_divisors = get_prime_divisors_with_pollard_rho(n);

    for (ll p : prime_divisors) {
        println(p);
    }

    return 0;
}
