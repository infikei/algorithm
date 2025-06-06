// Solve 2024-10-23

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

    string s;
    cin >> s;

    int n = size(s);
    char prev_c = s[0] - 1;
    int cur = 0;
    int ans = 0;

    for (char c : s) {
        if (c == prev_c + 1) {
            cur++;
        }
        else {
            if (cur == 3) {
                ans++;
            }

            cur = 1;
        }

        prev_c = c;
    }

    if (cur == 3) {
        ans++;
    }

    println(ans);

    return 0;
}
