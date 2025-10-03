// Solve 2025-10-03

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

// void precomputation() {
//     bool sieve[151];
//     memset(sieve, true, sizeof sieve);
//     sieve[1] = false;
//     vector<int> primes;

//     for (int i = 2; i <= 150; i++) {
//         if (sieve[i]) {
//             primes.push_back(i);

//             for (int j = i * 2; j <= 150; j += i) {
//                 sieve[j] = false;
//             }
//         }
//     }

//     // n = 3일 때 수열 찾기

//     for (int& a : primes) {
//         for (int& b : primes) {
//             for (int& c : primes) {
//                 int k = a * a + b * b + c * c;

//                 if (!(a == b && b == c) && k % a == 0 && k % b == 0 && k % c == 0) {
//                     cout << a << ' ' << b << ' ' << c << '\n';
//                 }
//             }
//         }
//     }

//     // n = 4일 때 수열 찾기

//     for (int& a : primes) {
//         for (int& b : primes) {
//             for (int& c : primes) {
//                 for (int& d : primes) {
//                     int k = a * a + b * b + c * c + d * d;

//                     if (!(a == b && b == c && c == d) && k % a == 0 && k % b == 0 && k % c == 0 && k % d == 0) {
//                         cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
//                     }
//                 }
//             }
//         }
//     }
// }

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n == 2) {
        // 불가능
        cout << -1 << '\n';
    }
    else if (n == 4) {
        // (2, 2, 3, 17) 활용
        cout << "2 2 3 17" << '\n';
    }
    else if (n % 3 == 0) {
        // (2, 5, 29) 활용
        int iter = n / 3;

        while (iter-- > 0) {
            cout << "2 5 29 ";
        }

        cout << '\n';
    }
    else if (n % 3 == 1) {
        // 2와 3 활용
        int iter = (n - 4) / 3;

        while (iter-- > 0) {
            cout << "2 2 2 ";
        }

        cout << "3 3 3 3" << '\n';
    }
    else {
        // 2와 3 활용
        int iter = (n - 2) / 3;

        while (iter-- > 0) {
            cout << "2 2 2 ";
        }

        cout << "3 3" << '\n';
    }

    return 0;
}
