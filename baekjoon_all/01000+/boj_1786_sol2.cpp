// Solve 2023-06-30
// Update 2024-12-11

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

vector<int> get_kmp_failure(string &p) {
    int m = size(p);
    vector<int> f(m, 0);

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = f[j - 1];
        }

        if (p[i] == p[j]) {
            f[i] = ++j;
        }
    }

    return f;
}

vector<int> kmp(string &s, string &p) {
    int n = size(s);
    int m = size(p);
    vector<int> f = get_kmp_failure(p);
    vector<int> res;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = f[j - 1];
        }

        if (s[i] == p[j]) {
            if (j == m - 1) {
                res.push_back(i - m + 1);
                j = f[j];
            }
            else {
                j++;
            }
        }
    }

    return res;
}

int main() {
    FASTIO;

    string s, p;
    getline(cin, s);
    getline(cin, p);

    vector<int> indexes = kmp(s, p);

    println(size(indexes));

    if (size(indexes) > 0) {
        for (int idx : indexes) {
            printw(idx + 1);
        }

        cout << '\n';
    }

    return 0;
}
