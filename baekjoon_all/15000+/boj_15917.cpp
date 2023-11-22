// Solve 2022-09-23
// Update 2023-11-22

// 2의 거듭제곱 판별 알고리즘

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int q;
    cin >> q;

    for (int qi = 0; qi < q; qi++) {
        int a;
        cin >> a;

        cout << ((a & (-a)) == a) << '\n';
    }

    return 0;
}
