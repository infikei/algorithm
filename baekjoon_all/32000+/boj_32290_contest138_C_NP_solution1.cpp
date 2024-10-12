// Solve 2024-10-07

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

bool visited[1024];

int main() {
    FASTIO;

    int l, r, x;
    cin >> l >> r >> x;

    for (int i = l; i <= r; i++) {
        visited[i | x] = true;
    }

    for (int i = 0; i < 1024; i++) {
        if (!visited[i]) {
            println(i);
            break;
        }
    }

    return 0;
}
