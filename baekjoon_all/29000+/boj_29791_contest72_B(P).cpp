// Solve 2023-09-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int a[1000000], b[1000000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);

    sort(b, b + m);

    int cnt_a = 1;
    int cur = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] >= cur + 100) {
            cnt_a++;
            cur = a[i];
        }
    }

    int cnt_b = 1;
    cur = b[0];

    for (int i = 1; i < m; i++) {
        if (b[i] >= cur + 360) {
            cnt_b++;
            cur = b[i];
        }
    }

    cout << cnt_a << ' ' << cnt_b << '\n';

    return 0;
}
