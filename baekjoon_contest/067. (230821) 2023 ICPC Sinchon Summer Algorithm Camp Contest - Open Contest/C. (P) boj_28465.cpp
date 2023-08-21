// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int f(int a, int b, int x, int y) {
    if (a == 1 || b == 1) return 1;

    if (a < b) {
        swap(a, b);
        swap(x, y);
    }

    int na = a - b;

    if (x < na) {
        return f(na, b, x, y);
    }
    else if (x < b) {
        int iter = 2;
        while (b != 1) {
            a -= b;
            swap(a, b);
            iter++;
        }
        return iter;
    }
    else {
        return f(na, b, x - b, y);
    }
}

int main() {
    FASTIO;

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    cout << f(a, b, x, y) << '\n';

    return 0;
}
