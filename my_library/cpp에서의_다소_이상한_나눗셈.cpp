#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    // 직접 실행하여 결과를 확인해보기

    for (int i = -5; i <= 5; i++) {
        cout << i << " / 3 = " << i / 3 << " ... " << i % 3 << '\n';
    }

    for (int i = -5; i <= 5; i++) {
        cout << i << " / (-3) = " << i / (-3) << " ... " << i % (-3) << '\n';
    }

    return 0;
}