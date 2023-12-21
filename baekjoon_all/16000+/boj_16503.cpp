// Solve 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc(int a, char op, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        int sign = 1;

        if (a < 0) {
            sign = -sign;
            a = -a;
        }
        if (b < 0) {
            sign = -sign;
            b = -b;
        }

        return a / b * sign;
    }

    return 1;
}

int main() {
    FASTIO;

    int n1, n2, n3;
    char op1, op2;
    cin >> n1 >> op1 >> n2 >> op2 >> n3;

    int ans1 = calc(calc(n1, op1, n2), op2, n3);
    int ans2 = calc(n1, op1, calc(n2, op2, n3));

    if (ans1 > ans2) swap(ans1, ans2);

    cout << ans1 << '\n';
    cout << ans2 << '\n';

    return 0;
}
