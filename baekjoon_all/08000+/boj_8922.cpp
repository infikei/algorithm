// Solve 2025-05-11

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

bool is_zero(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            return false;
        }
    }

    return true;
}

string is_finally_zero_or_loop(vector<int>& a, int n) {
    for (int i = 1; i <= 1000; i++) {
        vector<int> na(n);

        for (int j = 1; j < n; j++) {
            na[j - 1] = abs(a[j - 1] - a[j]);
        }

        na.back() = abs(a[0] - a.back());
        swap(a, na);

        if (is_zero(a)) {
            return "ZERO";
        }
    }

    return "LOOP";
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int& x : a) {
            cin >> x;
        }

        cout << is_finally_zero_or_loop(a, n) << '\n';
    }

    return 0;
}
