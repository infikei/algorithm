// Solve 2024-05-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp{
    bool operator()(string &a, string &b) {
        if (SIZE(a) != SIZE(b)) return SIZE(a) < SIZE(b);

        int aa = 0;
        int bb = 0;

        for (char c : a) {
            if (c <= '9') {
                aa += c - '0';
            }
        }

        for (char c : b) {
            if (c <= '9') {
                bb += c - '0';
            }
        }

        if (aa != bb) return aa < bb;
        return a < b;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp());

    for (string &s : v) {
        cout << s << '\n';
    }

    return 0;
}
