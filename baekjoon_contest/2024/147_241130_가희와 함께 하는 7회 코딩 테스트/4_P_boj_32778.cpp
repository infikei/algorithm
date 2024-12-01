// Solve 2024-11-30

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

int find_char(string s, char c) {
    for (int i = 0; i < size(s); i++) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}

int main() {
    FASTIO;

    string line;
    getline(cin, line);

    int open_char_pos = find_char(line, '(');

    if (open_char_pos == -1) {
        println(line);
        println("-");
    }
    else {
        println(line.substr(0, open_char_pos - 1));
        println(line.substr(open_char_pos + 1, size(line) - open_char_pos - 2));
    }

    return 0;
}
