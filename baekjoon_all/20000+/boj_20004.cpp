// Solve 2024-12-07
// Update 2025-03-02

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

int main() {
    FASTIO;

    int a;
    cin >> a;

    vector<int> answers = { 1, 2, 4, 5, 9, 14, 29 };

    for (int &ans : answers) {
        if (ans <= a) {
            cout << ans << '\n';
        }
    }

    return 0;
}
