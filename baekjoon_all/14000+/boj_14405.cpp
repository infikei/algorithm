// Solve 2024-12-30

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

    string words[3] = { "pi", "ka", "chu" };
    int i = 0;
    bool valid = true;

    while (i < size(s)) {
        bool found = false;

        for (string w : words) {
            if (i + size(w) <= size(s) && s.substr(i, size(w)) == w) {
                i += size(w);
                found = true;
                break;
            }
        }

        if (!found) {
            valid = false;
            break;
        }
    }

    println(valid ? "YES" : "NO");

    return 0;
}
