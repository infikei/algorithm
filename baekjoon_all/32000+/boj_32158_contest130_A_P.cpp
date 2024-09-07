// Solve 2024-09-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    vector<int> p, c;

    for (int i = 0; i < n; i++) {
        switch (s[i])
        {
        case 'P':
            p.push_back(i);
            break;
        case 'C':
            c.push_back(i);
            break;
        }
    }

    for (int i = 0; i < min(p.size(), c.size()); i++) {
        swap(s[p[i]], s[c[i]]);
    }

    cout << s << '\n';

    return 0;
}
