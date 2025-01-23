// Solve 2025-01-21
// Update 2025-01-23

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
    ll a_arr[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

    for (ll a : a_arr) {
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

void solution() {
    string s;
    cin >> s;

    ll n = stoll(s);

    if (!is_prime_with_miller_rabin(n)) {
        println("no");
        return;
    }

    reverse(all(s));

    for (char &c : s) {
        if (c == '3' || c == '4' || c == '7') {
            println("no");
            return;
        }
        else if (c == '6') {
            c = '9';
        }
        else if (c == '9') {
            c = '6';
        }
    }

    n = stoll(s);

    if (!is_prime_with_miller_rabin(n)) {
        println("no");
        return;
    }

    println("yes");
}

int main() {
    FASTIO;

    solution();

    return 0;
}
