// Solve 2023-05-06
// Update 2024-10-23

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

ll t[100000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    ll low = 0;
    ll high = 1e18;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        ll res = 0;

        for (int i = 0; i < n; i++) {
            res += mid / t[i];

            if (res >= m) {
                break;
            }
        }

        if (res >= m) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    println(high);

    return 0;
}
