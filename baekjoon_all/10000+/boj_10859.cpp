// Solve 2025-01-21

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

bool is_prime(ll n) {
    if (n == 1) return false;

    ll sqrt_n = sqrt(n);

    for (ll i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void solution() {
    string s;
    cin >> s;

    ll n = stoll(s);

    if (!is_prime(n)) {
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

    if (!is_prime(n)) {
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
