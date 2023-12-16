// Solve 2023-06-07
// Update 2023-12-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int tri_num[45] = { 0 };

    for (int i = 1; i <= 44; i++) {
        tri_num[i] = i * (i + 1) / 2;
    }

    bool check[1001] = { false };

    for (int a = 1; a <= 44; a++) {
        for (int b = a; b <= 44; b++) {
            int cur = tri_num[a] + tri_num[b];

            if (cur >= 1001) continue;

            for (int c = b; c <= 44; c++) {
                int cur2 = cur + tri_num[c];

                if (cur2 >= 1001) continue;

                check[cur2] = true;
            }
        }
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int k;
        cin >> k;

        cout << check[k] << '\n';
    }

    return 0;
}
