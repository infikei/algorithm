// Solve 2022-08-23
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool check(int k, int a) {
    if (a / 10 == k) return true;
    if (a % 10 == k) return true;
    return false;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    int cnt = 0;

    for (int h = 0; h <= n; h++) {
        if (check(k, h)) {
            cnt += 3600;
            continue;
        }
        else {
            for (int m = 0; m < 60; m++) {
                if (check(k, m)) {
                    cnt += 60;
                    continue;
                }
                else {
                    for (int s = 0; s < 60; s++) {
                        if (check(k, s)) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
