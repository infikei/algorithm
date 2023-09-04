// Solve 2023-09-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c, x[2], y[2];
    cin >> a >> b >> c;

    for (int i = 0; i < 2; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < 2; i++) {
        cin >> y[i];
    }

    int cnt[2] = { 0 };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int val = a * x[i] + b * y[j] + c;

            if (val < 0) cnt[0]++;
            else if (val > 0) cnt[1]++;
        }
    }

    if (cnt[0] >= 1 && cnt[1] >= 1) {
        cout << "Poor\n";
    }
    else {
        cout << "Lucky\n";
    }

    return 0;
}
