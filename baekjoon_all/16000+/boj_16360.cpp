// Solve 2024-12-12

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

    unordered_map<char, string> hs1;
    unordered_map<string, string> hs2;

    hs1['a'] = "as";
    hs1['i'] = "ios";
    hs1['y'] = "ios";
    hs1['l'] = "les";
    hs1['n'] = "anes";
    hs2["ne"] = "anes";
    hs1['o'] = "os";
    hs1['r'] = "res";
    hs1['t'] = "tas";
    hs1['u'] = "us";
    hs1['v'] = "ves";
    hs1['w'] = "was";

    int n;
    cin >> n;

    while (n-- > 0) {
        string s;
        cin >> s;

        if (hs1.find(s.back()) != hs1.end()) {
            string p = hs1[s.back()];
            s.pop_back();

            for (char c : p) {
                s.push_back(c);
            }

            println(s);
            continue;
        }

        string w = s.substr(size(s) - 2, 2);

        if (hs2.find(w) != hs2.end()) {
            string p = hs2[w];
            s.pop_back();
            s.pop_back();

            for (char c : p) {
                s.push_back(c);
            }

            println(s);
            continue;
        }

        s.push_back('u');
        s.push_back('s');
        println(s);
    }

    return 0;
}
