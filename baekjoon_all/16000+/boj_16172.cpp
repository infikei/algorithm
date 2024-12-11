// Solve 2024-12-11

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

vector<int> get_pi(string &p) {
    int m = size(p);
    vector<int> pi(m, 0);
    int i = 1, j = 0;

    while (i < m) {
        if (p[i] == p[j]) {
            i++;
            j++;
            pi[i - 1] = j;
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = pi[j - 1];
            }
        }
    }

    return pi;
}

vector<int> kmp(string &s, string &p) {
    int n = size(s);
    int m = size(p);
    vector<int> pi = get_pi(p);
    vector<int> res;
    int i = 0, j = 0;

    while (i < n) {
        if (s[i] == p[j]) {
            i++;
            j++;

            if (j == m) {
                res.push_back(i - m);
                j = pi[j - 1];
            }
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = pi[j - 1];
            }
        }
    }

    return res;
}

int main() {
    FASTIO;

    string s, k;
    cin >> s >> k;

    string ns;

    for (char c : s) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            ns.push_back(c);
        }
    }

    vector<int> indexes = kmp(ns, k);

    println(indexes.empty() ? 0 : 1);

    return 0;
}
