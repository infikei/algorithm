// Solve 2022-07-30
// Update 2024-02-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int recur(int size, int r, int c) {
    if (size == 1) return 0;

    int half_size = size / 2;

    if (r < half_size) {
        if (c < half_size) {
            return recur(half_size, r, c);
        }
        else {
            return half_size * half_size + recur(half_size, r, c - half_size);
        }
    }
    else {
        if (c < half_size) {
            return half_size * half_size * 2 + recur(half_size, r - half_size, c);
        }
        else {
            return half_size * half_size * 3 + recur(half_size, r - half_size, c - half_size);
        }
    }
}

int main() {
    FASTIO;

    int n, r, c;
    cin >> n >> r >> c;

    cout << recur(1 << n, r, c) << '\n';

    return 0;
}
