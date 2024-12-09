// Solve 2024-12-09

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

    int cnt[26] = { 0 };

    for (char c : s) {
        cnt[c - 'a']++;
    }

    int max_cnt = 0;
    char max_char = 'a';

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > max_cnt) {
            max_cnt = cnt[i];
            max_char = 'a' + i;
        }
    }

    printw(max_char);
    println(max_cnt);

    return 0;
}
