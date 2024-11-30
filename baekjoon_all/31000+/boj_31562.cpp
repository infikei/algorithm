// Solve 2024-11-29

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

    unordered_map<string, string> hs;

    for (int i = 0; i < n; i++) {
        int t;
        string s;
        cin >> t >> s;

        string a;

        for (int j = 0; j < 3; j++) {
            char aj;
            cin >> aj;

            a.push_back(aj);
        }

        for (int j = 3; j < 7; j++) {
            char aj;
            cin >> aj;
        }

        if (hs.find(a) == hs.end()) {
            hs[a] = s;
        }
        else {
            hs[a] = "?";
        }
    }

    for (int i = 0; i < m; i++) {
        string b;

        for (int j = 0; j < 3; j++) {
            char bj;
            cin >> bj;

            b.push_back(bj);
        }

        if (hs.find(b) == hs.end()) {
            println("!");
        }
        else {
            println(hs[b]);
        }
    }

    return 0;
}
