// Solve 2025-01-31

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

int arr[1400];

int main() {
    FASTIO;

    int m, n;
    cin >> m >> n;

    for (int day = 1; day <= n; day++) {
        int zeros, ones, twos;
        cin >> zeros >> ones >> twos;

        if (1 + zeros < m * 2) {
            arr[1 + zeros]++;
        }

        if (1 + zeros + ones < m * 2) {
            arr[1 + zeros + ones]++;
        }
    }

    arr[0] = 1;

    for (int i = 1; i < m * 2; i++) {
        arr[i] += arr[i - 1];
    }

    for (int x = 0; x < m; x++) {
        printw(arr[m - x]);

        for (int y = 1; y < m; y++) {
            printw(arr[m + y]);
        }

        cout << '\n';
    }

    return 0;
}
