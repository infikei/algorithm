// Solve 2024-12-02

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
    cin >> n;

    int a[4];

    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    if (s[0] != 'a' || s.back() != 'a') {
        println("No");
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            println("No");
            return 0;
        }
    }

    int cnt[4] = { 0 };

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; i < 4; i++) {
        if (cnt[i] > a[i]) {
            println("No");
            return 0;
        }
    }

    println("Yes");

    return 0;
}
