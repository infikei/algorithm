// Solve 2022-06-10
// Update 2023-08-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    for (int i = 0; i < 3; i++) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

        h2 -= h1;
        m2 -= m1;
        s2 -= s1;

        while (s2 < 0) {
            s2 += 60;
            m2--;
        }

        while (m2 < 0) {
            m2 += 60;
            h2--;
        }

        cout << h2 << ' ' << m2 << ' ' << s2 << '\n';
    }

    return 0;
}
