// Solve 2024-11-17

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

int c[6] = { 13, 7, 5, 3, 3, 2 };
int a[6], b[6];

int main() {
    FASTIO;

    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 6; i++) {
        cin >> b[i];
    }

    double aa = 0, bb = 0;

    for (int i = 0; i < 6; i++) {
        aa += a[i] * c[i];
    }

    for (int i = 0; i < 6; i++) {
        bb += b[i] * c[i];
    }

    bb += 1.5;

    if (aa > bb) {
        println("cocjr0208");
    }
    else {
        println("ekwoo");
    }

    return 0;
}
