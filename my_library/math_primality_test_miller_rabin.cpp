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

/**
 * @brief 모듈러 곱셈을 계산한다.
 * 
 * 주어진 두 정수 a와 b의 곱에 모듈러 연산 mod를 적용한 값을 구한다.
 * 
 * @param a 첫 번째 정수
 * @param b 두 번째 정수
 * @param mod 모듈러 값 (양수여야 함)
 * @return ll (a * b) % mod의 결과
 */
ll mod_mul(ll a, ll b, ll mod) {
    a %= mod;
    b %= mod;
    ull ua = a;
    ull res = 0;

    while (b > 0) {
        if (b & 1) {
            res = (res + ua) % mod;
        }

        ua = (ua * 2) % mod;
        b >>= 1;
    }

    return (ll) res;
}

/**
 * @brief 모듈러 거듭제곱을 계산한다.
 * 
 * 주어진 정수 a를 지수 p만큼 거듭제곱한 결과에 모듈러 연산 mod를 적용한다.
 * 
 * @param a 거듭제곱의 밑
 * @param p 거듭제곱의 지수
 * @param mod 모듈러 값 (양수여야 함)
 * @return ll (a^p) % mod의 결과
 */
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

/**
 * @brief 밀러-라빈 소수 판별법을 이용하여 주어진 수가 소수인지 확률적으로 판별한다.
 * 
 * 이 함수는 임의의 정수 a를 사용하여 주어진 홀수 n이 소수인지 확률적으로 판별한다.
 * 
 * @param n 판별할 정수
 * @param a 밀러-라빈 소수 판별법에서 사용할 정수 (2 <= a < n-1이어야 함)
 * @return true n이 소수일 가능성이 높은 경우
 * @return false n이 1 이하이거나 확실히 합성수인 경우
 * @warning 이 함수는 a가 2 <= a < n-1 범위 내에 있어야 제대로 동작한다.
 */
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

/**
 * @brief 밀러-라빈 소수 판별법을 이용하여 주어진 수가 소수인지 판별한다.
 * 
 * @param n 판별할 정수
 * @return true n이 소수인 경우
 * @return false n이 1 이하이거나 합성수인 경우
 */
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

int main() {
    FASTIO;

    return 0;
}
