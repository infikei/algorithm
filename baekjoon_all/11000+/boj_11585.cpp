// Solve 2024-12-13

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

int get_gcd(int a, int b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

vector<int> get_kmp_failure(string &p) {
    int m = size(p);
    vector<int> f(m, 0);
    int i = 1, j = 0;

    while (i < m) {
        if (p[i] == p[j]) {
            i++;
            j++;
            f[i - 1] = j;
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = f[j - 1];
            }
        }
    }

    return f;
}

int kmp(string &s, string &p) {
    int n = size(s);
    int m = size(p);
    vector<int> f = get_kmp_failure(p);
    int res = 0;
    int i = 0, j = 0;

    while (i < n) {
        if (s[i] == p[j]) {
            i++;
            j++;

            if (j == m) {
                res++;
                j = f[j - 1];
            }
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = f[j - 1];
            }
        }
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    string a(n * 2, ' ');

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    a.pop_back();

    string b(n, ' ');

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = kmp(a, b);
    int gcd = get_gcd(ans, n);
    cout << ans / gcd << '/' << n / gcd << '\n';

    return 0;
}
