// Solve 2024-08-31

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
    unordered_set<int> hs;
    hs.insert(0);

    for (int i = 1; i <= n; i++) {
        if (a - i < 0 || hs.find(a - i) != hs.end()) {
            a += i;
        }
        else {
            a -= i;
        }

        hs.insert(a);
    }

    cout << a << '\n';

    return 0;
}
