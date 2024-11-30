// Solve 2024-11-24

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

bool visited[101];

int main() {
    FASTIO;

    visited[1] = true;

    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            visited[i * j] = true;
        }
    }

    int n;
    cin >> n;

    println(visited[n]);

    return 0;
}
