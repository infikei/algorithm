// Solve 2023-08-13
// Update 2025-09-05

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    string s;
    int nxt_num = 0;

    for (int i = 0; i < 3; i++) {
        cin >> s;

        if (isdigit(s[0])) {
            nxt_num = stoi(s) + 3 - i;
        }
    }

    if (nxt_num % 3 == 0) {
        if (nxt_num % 5 == 0) {
            cout << "FizzBuzz" << '\n';
        }
        else {
            cout << "Fizz" << '\n';
        }
    }
    else {
        if (nxt_num % 5 == 0) {
            cout << "Buzz" << '\n';
        }
        else {
            cout << nxt_num << '\n';
        }
    }

    return 0;
}
