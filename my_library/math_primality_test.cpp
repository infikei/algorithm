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
 * @brief 주어진 정수가 소수인지 판별한다.
 * 
 * 이 함수는 주어진 정수가 소수인지 확인한다. 소수는 1과 자기 자신으로만 나누어떨어지는 1보다 큰 자연수이다.
 * 
 * @param n 판별할 정수
 * @return true 주어진 정수가 양수이고 소수인 경우
 * @return false 주어진 정수가 양수가 아니거나 소수가 아닌 경우
 * @note 이 함수는 정수 k의 제곱근까지만 검사하여 최적화되었다.
 */
bool is_prime(ll n) {
    if (n <= 1) return false;

    ll sqrt_n = sqrt(n);

    for (ll i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
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

int main() {
    FASTIO;

    return 0;
}
