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

int main() {
    FASTIO;

    return 0;
}
