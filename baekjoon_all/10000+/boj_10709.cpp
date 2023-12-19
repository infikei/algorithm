// Solve 2023-04-07
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int h, w;
    cin >> h >> w;

    for (int row = 0; row < h; row++) {
        int cloud_time = -1;

        for (int col = 0; col < w; col++) {
            char cloud;
            cin >> cloud;

            if (cloud == 'c') {
                cloud_time = 0;
            }
            else if (cloud_time > -1) {
                cloud_time++;
            }

            cout << cloud_time << ' ';
        }

        cout << '\n';
    }

    return 0;
}
