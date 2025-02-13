// Solve 2025-02-12

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

bool sieve[40000];
vector<int> primes;

int main() {
    FASTIO;

    for (int i = 2; i < 40000; i++) {
        if (sieve[i]) continue;

        primes.push_back(i);

        for (int j = i * 2; j < 40000; j += i) {
            sieve[j] = true;
        }
    }

    int a, b;
    cin >> a >> b;

    if (b % a != 0) {
        println(0);
        return 0;
    }

    int k = b / a;
    int ans = 1;

    for (int &p : primes) {
        int cnt = 0;

        while (k % p == 0) {
            k /= p;
            cnt++;
        }

        ans *= (cnt + 1);
    }

    if (k > 1) {
        ans *= 2;
    }

    println(ans);

    return 0;
}
