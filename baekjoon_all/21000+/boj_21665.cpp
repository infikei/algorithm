// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> img(n);

    for (string &s : img) {
        cin >> s;
    }

    vector<string> img2(n);

    for (string &s : img2) {
        cin >> s;
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (img[i][j] == img2[i][j]) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
