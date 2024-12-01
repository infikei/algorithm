// Solve 2024-12-01

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

int get_gcd(int a, int b) {
    int r = a % b;

    return r == 0 ? b : get_gcd(b, r);
}

int get_lcm(int a, int b) {
    int gcd = get_gcd(a, b);
    return a / gcd * b;
}

int main() {
    FASTIO;

    int n, a, b;
    cin >> n >> a >> b;

    int fizz = n / a;
    int buzz = n / b;
    int fizzbuzz = n / get_lcm(a, b);
    fizz -= fizzbuzz;
    buzz -= fizzbuzz;

    printw(fizz);
    printw(buzz);
    println(fizzbuzz);

    return 0;
}
