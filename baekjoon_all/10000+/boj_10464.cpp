// Solve 2024-02-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int xor_from_zero(int n) {
    int left = n % 2 == 0 ? n : 0;
    int right = (n % 4 == 1 || n % 4 == 2) ? 1 : 0;
    return left + right;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int start, finish;
        cin >> start >> finish;
        cout << (xor_from_zero(start - 1) ^ xor_from_zero(finish)) << '\n';
    }

    return 0;
}
