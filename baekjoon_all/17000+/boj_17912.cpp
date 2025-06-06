// Solve 2025-06-06

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

    int n;
    cin >> n;

    int min_space_junk = 1000000000;
    int day_of_min_space_junk = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x < min_space_junk) {
            min_space_junk = x;
            day_of_min_space_junk = i;
        }
    }

    cout << day_of_min_space_junk << '\n';

    return 0;
}
