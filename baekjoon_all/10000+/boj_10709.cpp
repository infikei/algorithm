// Solve 2023-04-07

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int h, w;
    cin >> h >> w;

    for (int row = 0; row < h; row++) {
        int x = -1;
        for (int col = 0; col < w; col++) {
            char cloud;
            cin >> cloud;

            if (cloud == 'c') {
                x = 0;
            }
            else if (x > -1) {
                x++;
            }
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
