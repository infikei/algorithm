// Solve 2025-02-18

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

int id[300];

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        int g;
        cin >> g;

        for (int i = 0; i < g; i++) {
            cin >> id[i];
        }

        int m = g;

        while (true) {
            vector<bool> visited(m);
            bool valid = true;

            for (int i = 0; i < g; i++) {
                int ii = id[i] % m;

                if (visited[ii]) {
                    valid = false;
                    break;
                }

                visited[ii] = true;
            }

            if (valid) break;

            m++;
        }

        cout << m << '\n';
    }

    return 0;
}
