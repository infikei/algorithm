// Solve 2025-01-06

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

int a[1000];

int main() {
    FASTIO;

    int p, n;
    cin >> p >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int i = 0;

    while (i < n && p < 200) {
        p += a[i];
        i++;
    }

    println(i);

    return 0;
}
