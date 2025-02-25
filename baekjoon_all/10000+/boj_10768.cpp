// Solve 2022-10-16
// Update 2025-02-25

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

    int month, day;
    cin >> month >> day;

    int mmdd = month * 100 + day;

    if (mmdd < 218) {
        cout << "Before" << '\n';
    }
    else if (mmdd > 218) {
        cout << "After" << '\n';
    }
    else {
        cout << "Special" << '\n';
    }

    return 0;
}
