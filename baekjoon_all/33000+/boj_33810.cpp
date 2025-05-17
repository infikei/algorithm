// Solve 2025-05-16

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string original = "SciComLove";
    string changed;
    cin >> changed;

    int diff_cnt = 0;

    for (int i = 0; i < 10; i++) {
        if (original[i] != changed[i]) {
            diff_cnt++;
        }
    }

    cout << diff_cnt << '\n';

    return 0;
}
