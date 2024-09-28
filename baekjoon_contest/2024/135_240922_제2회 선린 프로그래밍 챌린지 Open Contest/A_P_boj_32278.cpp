// Solve 2024-09-22

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETPRECISION(n) cout << fixed << setprecision(n);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    if (n < -2147483648 || n > 2147483647) {
        cout << "long long\n";
    }
    else if (n < -32768 || n > 32767) {
        cout << "int\n";
    }
    else {
        cout << "short\n";
    }

    return 0;
}
