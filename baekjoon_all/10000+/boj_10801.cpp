// Solve 2022-08-20
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

    int a[10], b[10];

    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 10; i++) {
        cin >> b[i];
    }

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        if (a[i] > b[i]) {
            ans++;
        }
        else if (a[i] < b[i]) {
            ans--;
        }
    }

    if (ans > 0) {
        cout << "A\n";
    }
    else if (ans < 0) {
        cout << "B\n";
    }
    else {
        cout << "D\n";
    }

    return 0;
}
