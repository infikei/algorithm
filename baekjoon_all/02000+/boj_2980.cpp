// Solve 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    int pos = 0, cur = 0;

    for (int i = 0; i < n; i++) {
        int d, r, g;
        cin >> d >> r >> g;

        // 이전 위치에서 각 신호등까지 이동
        cur += d - pos;
        pos = d;

        // 각 신호등에서 빨간 불이면 대기
        cur += max(0, r - cur % (r + g));
    }

    // 마지막 신호등부터 도로 끝까지 이동
    cur += l - pos;

    cout << cur << '\n';

    return 0;
}
