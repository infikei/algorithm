#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int m, n, q, a[1001], p[1001];
    cin >> m >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cout << "? " << i << ' ' << i << endl;
        cin >> p[i];
        p[i] = p[i] % a[i] + 1;
    }
    for (int i = m + 1; i <= n; i++) {
        p[i] = 1;
    }

    cout << '!';
    for (int i = 1; i <= n; i++) {
        cout << ' ' << p[i];
    }
    cout << endl;

    return 0;
}