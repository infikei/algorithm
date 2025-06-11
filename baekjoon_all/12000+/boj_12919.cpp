// Solve 2025-06-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int recur(string& s, string& t) {
    if (s.size() == t.size()) {
        return s == t ? 1 : 0;
    }

    if (t[0] == 'B') {
        string nt = t.substr(1, t.size() - 1);
        reverse(nt.begin(), nt.end());

        if (recur(s, nt) == 1) return 1;
    }

    if (t.back() == 'A') {
        t.pop_back();

        if (recur(s, t) == 1) return 1;

        t.push_back('A');
    }

    return 0;
}

int main() {
    FASTIO;

    string s, t;
    cin >> s >> t;

    cout << recur(s, t) << '\n';

    return 0;
}
