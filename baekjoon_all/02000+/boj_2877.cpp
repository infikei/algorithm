// Solve 2022-09-04
// Update 2025-03-22

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

    int k;
    cin >> k;

    k++;
    string ans;

    while (k > 1) {
        if (k % 2 == 0) {
            ans.push_back('4');
        }
        else {
            ans.push_back('7');
        }

        k /= 2;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}
