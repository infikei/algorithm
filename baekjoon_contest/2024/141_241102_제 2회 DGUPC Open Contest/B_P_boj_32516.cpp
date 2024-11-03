// Solve 2024-11-02

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

    int ans = 0;
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (s[i] == '?' && s[j] == '?') {
            ans += 26;
        }
        else if (s[i] == '?' || s[j] == '?') {
            ans++;
        }
        else if (s[i] != s[j]) {
            ans = 0;
            break;
        }

        i++;
        j--;
    }

    println(ans);

    return 0;
}
