// Solve 2025-01-19

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

pii keyboard[128];

void set_keyboard(int num, string s) {
    for (int i = 0; i < size(s); i++) {
        keyboard[s[i]] = { num, i + 1 };
    }
}

int main() {
    FASTIO;

    set_keyboard(1, " ");
    set_keyboard(2, "ABC");
    set_keyboard(3, "DEF");
    set_keyboard(4, "GHI");
    set_keyboard(5, "JKL");
    set_keyboard(6, "MNO");
    set_keyboard(7, "PQRS");
    set_keyboard(8, "TUV");
    set_keyboard(9, "WXYZ");

    int p, w;
    cin >> p >> w;
    cin.ignore();

    string s;
    getline(cin, s);

    int p_cnt = keyboard[s[0]].second;
    int w_cnt = 0;

    for (int i = 1; i < size(s); i++) {
        p_cnt += keyboard[s[i]].second;

        if (s[i] != ' ' && keyboard[s[i - 1]].first == keyboard[s[i]].first) {
            w_cnt++;
        }
    }

    int ans = p * p_cnt + w * w_cnt;
    println(ans);

    return 0;
}
