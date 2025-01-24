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
inline lll get_mod_mul(lll a, lll b, lll mod) {
#ifdef BOJ
    return a * b % mod;
#else
    a %= mod;
    b %= mod;
    ull ua = a;
    ull res = 0;

    while (b > 0) {
        if (b & 1) {
            res = (res + ua) % mod;
        }

        ua = (ua << 1) % mod;
        b >>= 1;
    }

    return (ll) res;
#endif
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
ll get_mod_pow(ll a, ll p, ll mod) {
    a %= mod;
    ll res = 1;

    while (p > 0) {
        if (p & 1) {
            res = get_mod_mul(res, a, mod);
        }

        a = get_mod_mul(a, a, mod);
        p >>= 1;
    }

    return res;
}

/**
 * @brief 주어진 두 정수의 최대공약수(GCD)를 구한다.
 * 
 * 이 함수는 유클리드 호제법(Euclidean Algorithm)을 이용하여 두 정수 a와 b의 최대공약수를 계산한다.
 * 최대공약수(GCD, Greatest Common Divisor)는 두 정수의 공통 약수 중에서 가장 큰 양의 정수이다.
 * 
 * @param a 첫 번째 정수
 * @param b 두 번째 정수
 * @return ll 주어진 두 정수의 최대공약수
 * @retval 두 정수 중 하나가 0이고 다른 하나가 0이 아닌 경우, 최대공약수는 수학적으로 0이 아닌 정수의 절댓값으로 정의된다.
 * @retval 두 정수가 모두 0인 경우 최대공약수는 0으로 정의된다.
 * @note 유클리드 호제법은 재귀적으로 a % b를 계산하며, b가 0일 때 종료된다.
 */
ll get_gcd(ll a, ll b) {
    if (b == 0) return a;

    return get_gcd(b, a % b);
}

/**
 * @brief 주어진 두 정수의 최소공배수(LCM)를 구한다.
 * 
 * 이 함수는 두 정수의 최대공약수(GCD)를 활용하여 최소공배수를 계산한다.
 * 최소공배수(LCM, Least Common Multiple)는 두 정수의 공통 배수 중에서 가장 작은 양의 정수이다.
 * 
 * 계산 공식: LCM(a, b) = (a / GCD(a, b)) * b
 * 
 * @param a 첫 번째 정수
 * @param b 두 번째 정수
 * @return ll 주어진 두 정수의 최소공배수
 * @retval 두 정수 중 하나 이상이 0인 경우, 최소공배수는 0으로 정의된다.
 */
ll get_lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;

    return a / get_gcd(a, b) * b;
}

/**
 * @brief 에라토스테네스의 체를 사용하여 소수를 판별한다.
 * 
 * 이 함수는 에라토스테네스의 체 알고리즘을 이용하여 `max_num` 이하의 모든 소수를 판별한다.
 * 반환되는 벡터의 각 인덱스 i는 정수 i가 소수인지 여부를 나타낸다.
 * 
 * @param max_num 소수를 판별할 최대 숫자 (0 이상)
 * @return vector<bool> 크기가 `max_num + 1`인 벡터로,
 *         인덱스 i가 true이면 i는 소수, false이면 소수가 아님을 의미한다.
 * @note 0과 1은 항상 소수가 아니다.
 */
vector<bool> create_sieve_of_eratosthenes_v1(int max_num) {
    vector<bool> sieve(max_num + 1, true);
    sieve[0] = sieve[1] = false; // 0과 1은 소수가 아님을 기록한다.

    for (int i = 2; i <= max_num; i++) {
        if (!sieve[i]) continue; // i가 소수가 아니면 skip한다.

        for (int j = i + i; j <= max_num; j += i) {
            sieve[j] = false; // 소수가 아님을 기록한다.
        }
    }

    return sieve;
}

/**
 * @brief 에라토스테네스의 체를 사용하여 소수를 판별한다.
 * 
 * 이 함수는 에라토스테네스의 체 알고리즘을 이용하여 `max_num` 이하의 모든 소수를 판별한다.
 * 반환되는 벡터의 각 인덱스 i는 정수 i가 소수인지 여부를 나타낸다.
 * 
 * @param max_num 소수를 판별할 최대 숫자 (0 이상)
 * @return vector<bool> 크기가 `max_num + 1`인 벡터로,
 *         인덱스 i가 true이면 i는 소수, false이면 소수가 아님을 의미한다.
 * @note 0과 1은 항상 소수가 아니다.
 */
vector<bool> create_sieve_of_eratosthenes_v2(int max_num) {
    vector<bool> sieve(max_num + 1, true);
    sieve[0] = sieve[1] = false; // 0과 1은 소수가 아님을 기록한다.

    int sqrt_max_num = sqrt(max_num);

    for (int i = 2; i <= sqrt_max_num; i++) {
        if (!sieve[i]) continue; // i가 소수가 아니면 skip한다.

        for (int j = i * i; j <= max_num; j += i) {
            sieve[j] = false; // 소수가 아님을 기록한다.
        }
    }

    return sieve;
}

/**
 * @brief a * x + b * y = gcd(a, b)를 만족하는 gcd(a, b)와 x와 y를 구한다.
 * 
 * 이 함수는 확장된 유클리드 호제법(Extended Euclidean Algorithm)을 이용하여
 * 두 정수 a와 b의 최대공약수(GCD)를 계산하고, 동시에 정수 계수 x와 y를 구한다.
 * 이 계수는 베주 항등식(Bezout's identity)을 만족한다 : a * x + b * y = gcd(a, b).
 * 
 * @param a 첫 번째 정수
 * @param b 두 번째 정수
 * @return vector<ll> 크기가 3인 벡터로, [gcd(a, b), x, y]를 반환한다.
 * @note a 또는 b가 0인 경우, gcd는 |a + b|이며, 다른 계수는 적절히 조정된다.
 * @warning 주어진 값이 너무 크면 오버플로우가 발생할 수 있으므로 주의가 필요하다.
 */
vector<ll> get_eed(ll a, ll b) {
    ll r0 = a, r1 = b;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;

    while (r1 > 0) {
        ll q = r0 / r1;
        ll r2 = r0 - q * r1;
        ll s2 = s0 - q * s1;
        ll t2 = t0 - q * t1;

        r0 = r1; r1 = r2;
        s0 = s1; s1 = s2;
        t0 = t1; t1 = t2;
    }

    return { r0, s0, t0 }; // gcd(a, b)와 x와 y
}

/** 
 * @brief 확장된 유클리드 호제법을 이용하여 모듈로 곱셈 역원을 구한다.
 * 
 * 즉, 주어진 두 정수 n과 a에 대하여 a * b = 1 (mod n)을 만족하는 정수 b를 구한다.
 * 
 * @param n 첫 번째 정수
 * @param a 두 번째 정수
 * @return ll a * b = 1 (mod n)을 만족하는 정수 b
 */
ll get_eed_inv(ll n, ll a) {
    vector<ll> eed = get_eed(n, a);
    // eed에는 nx + ay = gcd(n, a)를 만족하는 gcd(n, a), x, y가 들어있다.

    // n과 a가 서로소가 아닌 경우, 모듈로 곱셈 역원은 존재하지 않는다.
    // 이 경우 -1을 대신 반환한다.
    if (eed[0] != 1) {
        return -1;
    }

    // 이제 주어진 n, a, x, y는 nx + ay = 1을 만족한다.
    // 위의 식은 ay = 1 - nx로 나타낼 수 있고 이는 ay = 1 (mod n)을 의미한다.
    // 따라서 b = y (mod n)을 만족한다.
    // 이제 이 값을 0 이상 n 미만의 정수로 만들어서 반환한다.
    ll b = eed[2];

    while (b < 0) {
        b += n;
    }

    return b;
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
    ll a_pow = get_mod_pow(a, d, n);

    if (a_pow == 1 || a_pow == n - 1) return true;

    // 0 <= r < s인 어떤 r에 대해 a^(2^r * d) mod n이 -1이면 소수일 가능성이 높다.
    for (int r = 1; r < s; r++) {
        a_pow = get_mod_mul(a_pow, a_pow, n);

        if (a_pow == n - 1) return true;
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

    // 32비트 정수 범위에서는 2, 7, 61에 대해서 테스트를 모두 통과하면 소수이다.
    // a_list[3] = { 2, 7, 61 };
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

/**
 * @brief 주어진 정수가 소수인지 판별한다.
 * 
 * 이 함수는 주어진 정수가 소수인지 확인한다.
 * 소수는 1과 자기 자신으로만 나누어떨어지는 1보다 큰 자연수이다.
 * 
 * @param n 판별할 정수
 * @return true 주어진 정수가 양수이고 소수인 경우
 * @return false 주어진 정수가 양수가 아니거나 소수가 아닌 경우
 * @note 이 함수는 정수 k의 제곱근까지만 검사하여 최적화되었다.
 */
bool is_prime_with_small_number(int n) {
    if (n <= 1) return false;

    int sqrt_n = sqrt(n);

    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

/**
 * @brief 주어진 정수가 소수인지 판별한다.
 * 
 * 이 함수는 주어진 정수가 소수인지 확인한다.
 * 소수는 1과 자기 자신으로만 나누어떨어지는 1보다 큰 자연수이다.
 * 
 * @param n 판별할 정수
 * @return true 주어진 정수가 양수이고 소수인 경우
 * @return false 주어진 정수가 양수가 아니거나 소수가 아닌 경우
 */
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    if (n <= 10000) return is_prime_with_small_number(n);
    return is_prime_with_miller_rabin(n);
}

/**
 * @brief 폴라드 로 알고리즘을 이용하여 주어진 정수의 소수인 약수를 찾는다.
 * 
 * 이 함수는 폺라드 로(Pollard's Rho) 알고리즘을 이용하여 매우 효율적으로 정수 n의 소수인 약수를 찾는다.
 * 폴라드 로 알고리즘은 확률적 방법에 기반하며, 수열의 반복과 최대공약수 계산을 통해 n의 약수를 구한다.
 * 
 * @param n 소수 약수를 구하려는 정수
 * @return ll 주어진 정수 n의 소수인 약수 (n이 1인 경우에는 1을 반환)
 */
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
        x = (get_mod_mul(x, x, n) + c) % n;

        // y = h(y)를 계산한다.
        y = (get_mod_mul(y, y, n) + c) % n;
        y = (get_mod_mul(y, y, n) + c) % n;

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

    return 0;
}
