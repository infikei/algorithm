// Solve 2023-07-11

// 주의 필요 : 이 풀이에는 확인되지 않은 반례가 존재할 수 있음.

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using ld = long double;

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    cout << (int)(b * log10l((ld)a)) + 1 << '\n';

    return 0;
}
