// Solve 2025-03-02

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

string wrong_times(int a, int b) {
    string res;

    while (a > 0 && b > 0) {
        int aa = a % 10;
        a /= 10;
        int bb = b % 10;
        b /= 10;

        int x = aa * bb;

        if (x < 10) {
            res.push_back('0' + x);
        }
        else {
            res.push_back('0' + x % 10);
            res.push_back('0' + x / 10);
        }
    }

    while (a > 0) {
        res.push_back('0' + a % 10);
        a /= 10;
    }

    while (b > 0) {
        res.push_back('0' + b % 10);
        b /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int a, b;
        cin >> a >> b;

        string a_wrong_times_b = wrong_times(a, b);
        string a_times_b = to_string((ll) a * b);

        if (a_times_b == a_wrong_times_b) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
