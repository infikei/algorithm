// Solve 2024-11-03

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

    int n, m;
    cin >> n >> m;

    vector<pii> hands;

    for (int u = 1; u <= m; u++) {
        int h1, h2;
        cin >> h1 >> h2;

        hands.emplace_back(h1, u);
        hands.emplace_back(h2, u);
    }

    sort(all(hands));

    println(hands[(n - 1) % (m * 2)].second);

    return 0;
}
