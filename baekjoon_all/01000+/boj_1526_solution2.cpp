// Solve 2023-12-31
// Update 2025-03-03

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

int find_max_four_seven_number(int n) {
    for (int k = n; k >= 4; k--) {
        string k_str = to_string(k);
        bool four_seven = true;

        for (char &c : k_str) {
            if (c != '4' && c != '7') {
                four_seven = false;
                break;
            }
        }

        if (four_seven) {
            return k;
        }
    }

    return -1;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = find_max_four_seven_number(n);

    cout << ans << '\n';

    return 0;
}
