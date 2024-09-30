// Solve 2024-09-28

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
    string s;
    cin >> n >> s;

    int ana_cnt = 0;
    int n_cnt = 2;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            if (n_cnt == 1) {
                ana_cnt++;
            }

            n_cnt = 0;
        }
        else if (s[i] == 'N') {
            n_cnt++;
        }
    }

    println(ana_cnt);

    return 0;
}
