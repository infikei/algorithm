// Solve 2022-11-25
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int num[3];

    for (int i = 0; i < 3; i++) {
        cin >> num[i];
    }

    sort(num, num + 3);

    if (num[0] == num[2]) {
        cout << 2 << '\n';
    }
    else if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2]) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
