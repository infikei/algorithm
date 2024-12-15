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

void kmp_failure(string &p, vector<int> &f) {
    int m = size(p);
    f.assign(m, 0);
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
}

int main() {
    FASTIO;

    string s;
    int n;
    cin >> s >> n;

    vector<string> p(n, "");
    vector<vector<int>> f(n, vector<int>());

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        kmp_failure(p[i], f[i]);
    }

    vector<int> j(n, 0);
    vector<int> memo(size(s) + 1, 0);

    for (int i = 0; i < size(s); i++) {
        for (int k = 0; k < n; k++) {
            while (j[k] > 0 && s[i] != p[k][j[k]]) {
                j[k] = f[k][j[k] - 1];
            }

            if (s[i] == p[k][j[k]]) {
                j[k]++;

                if (j[k] == size(p[k])) {
                    memo[i + 1] = max(memo[i + 1], memo[i + 1 - size(p[k])] + size(p[k]));
                    j[k] = f[k][j[k] - 1];
                }
            }
        }

        memo[i + 1] = max(memo[i + 1], memo[i]);
    }

    println(memo.back());

    return 0;
}
