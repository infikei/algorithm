// Solve 2025-01-28

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

int arr[15][15];

int main() {
    FASTIO;

    for (int j = 0; j <= 14; j++) {
        arr[0][j] = j;
    }

    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int k, n;
        cin >> k >> n;

        println(arr[k][n]);
    }

    return 0;
}
