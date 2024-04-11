// Solve 2022-11-06
// Update 2024-04-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc(int x) {
    int res = 0;
    int cnt = 0;
    int i = 1;

    while (true) {
        if (cnt + i <= x) {
            res += i * i;
            cnt += i;
            i++;
        }
        else {
            res += i * (x - cnt);
            break;
        }
    }

    return res;
}

int main() {
    FASTIO;

    int a, b;
    cin >> a >> b;

    cout << calc(b) - calc(a - 1) << '\n';

    return 0;
}
