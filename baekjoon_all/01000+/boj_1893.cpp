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

bool kmp(string &s, string &p) {
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
                if (++res == 2) {
                    return false;
                }

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

    return res == 1;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    char conv[128];

    while (t-- > 0) {
        string a, w, s;
        cin >> a >> w >> s;

        for (int i = 1; i < size(a); i++) {
            conv[a[i - 1]] = a[i];
        }

        conv[a.back()] = a[0];
        vector<int> ans;

        if (kmp(s, w)) {
            ans.push_back(0);
        }

        for (int i = 1; i < size(a); i++) {
            for (char &c : w) {
                c = conv[c];
            }

            if (kmp(s, w)) {
                ans.push_back(i);
            }
        }

        if (ans.empty()) {
            println("no solution");
        }
        else if (size(ans) == 1) {
            printw("unique:");
            println(ans[0]);
        }
        else {
            printw("ambiguous:");

            for (int a : ans) {
                printw(a);
            }

            cout << '\n';
        }
    }

    return 0;
}
