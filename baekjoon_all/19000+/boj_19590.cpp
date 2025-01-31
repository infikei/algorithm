// Solve 2025-01-29

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll bead_sum = 0;
    int max_bead = 0;

    for (int i = 0; i < n; i++) {
        int bead;
        cin >> bead;

        max_bead = max(max_bead, bead);
        bead_sum += bead;
    }

    ll bead_others = bead_sum - max_bead;

    if (max_bead > bead_others) {
        println(max_bead - bead_others);
    }
    else {
        println(bead_sum % 2);
    }

    return 0;
}
