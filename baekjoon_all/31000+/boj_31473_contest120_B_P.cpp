// Solve 2024-03-03

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

    int a = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += x;
    }

    int b = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b += x;
    }

    cout << b << ' ' << a << '\n';

    return 0;
}
