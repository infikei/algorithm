// Solve 2025-04-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int solution(int a, int b, int c, int d) {
    // a를 모르는 경우
    if (a == -1) {
        if (b + d == c + c) {
            int res = b + b - c;

            if (res >= 1 && res <= 10000) return res;
        }

        int x = c / b;

        if (b * x == c && c * x == d && b % x == 0) {
            int res = b / x;

            if (res >= 1 && res <= 10000) return res;
        }

        return -1;
    }

    // b를 모르는 경우
    if (b == -1) {
        if (c - a == (d - c) * 2) {
            int res = (a + c) / 2;

            if (res >= 1 && res <= 10000) return res;
        }

        if (d % c == 0 && (ll) c * c * c == (ll) a * d * d) {
            int ac = a * c;
            int res = sqrt(ac);

            if (res >= 1 && res <= 10000 && res * res == ac) return res;
        }

        return -1;
    }

    // c를 모르는 경우
    if (c == -1) {
        if ((b - a) * 2 == d - b) {
            int res = (b + d) / 2;

            if (res >= 1 && res <= 10000) return res;
        }

        if (b % a == 0 && (ll) b * b * b == (ll) a * a * d) {
            int bd = b * d;
            int res = sqrt(bd);

            if (res >= 1 && res <= 10000 && res * res == bd) return res;
        }

        return -1;
    }

    // d를 모르는 경우

    if (a + c == b + b) {
        int res = c + c - b;

        if (res >= 1 && res <= 10000) return res;
    }

    int x = b / a;

    if (a * x == b && b * x == c) {
        int res = c * x;

        if (res >= 1 && res <= 10000) return res;
    }

    return -1;
}

int main() {
    FASTIO;

    while (true) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == -1 && b == -1 && c == -1 && d == -1) break;

        cout << solution(a, b, c, d) << '\n';
    }

    return 0;
}
