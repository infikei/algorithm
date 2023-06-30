// Solve 2023-06-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<int> get_pi(const string &p) {
    vector<int> pi(SIZE(p), 0);

    int i = 1, j = 0;
    while (i < SIZE(p)) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
        i++;
    }

    return pi;
}

vector<int> kmp_search(const string &t, const string &p, const vector<int> &pi) {
    vector<int> kmp;

    int i = 0, j = 0;
    while (i < SIZE(t)) {
        while (j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }
        if (t[i] == p[j]) {
            j++;
            if (j == SIZE(p)) {
                kmp.push_back(i - SIZE(p) + 1);
                j = pi[j - 1];
            }
        }
        i++;
    }

    return kmp;
}

int main() {
    FASTIO;

    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> pi = get_pi(p);
    vector<int> kmp = kmp_search(t, p, pi);

    cout << SIZE(kmp) << '\n';
    if (SIZE(kmp) > 0) {
        for (auto x : kmp) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
