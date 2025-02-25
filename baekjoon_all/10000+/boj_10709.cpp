// Solve 2023-04-07
// Update 2025-02-25

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int h, w;
    cin >> h >> w;

    for (int x = 0; x < h; x++) {
        int cloud_time = -1;

        for (int y = 0; y < w; y++) {
            char cloud;
            cin >> cloud;

            if (cloud == 'c') {
                cloud_time = 0;
            }
            else if (cloud_time >= 0) {
                cloud_time++;
            }

            cout << cloud_time << ' ';
        }

        cout << '\n';
    }

    return 0;
}
