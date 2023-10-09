// Solve 2022-11-21
// Update 2023-10-08

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
    cin >> n;

    for (int ni = 1; ni <= n; ni++) {
        string s;
        cin >> s;

        for (char &ch : s) {
            if (++ch > 'Z') ch = 'A';
        }

        if (ni >= 2) cout << '\n';

        cout << "String #" << ni << '\n' << s << '\n';
    }

    return 0;
}
