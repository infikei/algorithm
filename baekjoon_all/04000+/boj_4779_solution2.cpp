// Solve 2023-03-27
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

void print_cantor(int k, int len) {
    if (k == 0) {
        cout << '-';
        return;
    }

    int nlen = len / 3;

    print_cantor(k - 1, nlen);

    for (int i = 0; i < nlen; i++) {
        cout << ' ';
    }

    print_cantor(k - 1, nlen);
}

int main() {
    FASTIO;

    int n;

    while (cin >> n) {
        int len = 1;
        for (int i = 0; i < n; i++) {
            len *= 3;
        }

        print_cantor(n, len);

        cout << '\n';
    }

    return 0;
}
