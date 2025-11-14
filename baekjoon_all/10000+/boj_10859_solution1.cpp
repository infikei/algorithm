// Solve 2025-01-21
// Update 2025-11-11

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

char conv[128];

bool is_prime(ll n) {
    if (n == 1) return false;

    ll sqrt_n = sqrt(n);

    for (ll i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    conv['0'] = '0';
    conv['1'] = '1';
    conv['2'] = '2';
    conv['3'] = '.';
    conv['4'] = '.';
    conv['5'] = '5';
    conv['6'] = '9';
    conv['7'] = '.';
    conv['8'] = '8';
    conv['9'] = '6';

    string s;
    cin >> s;
    ll n = stoll(s);

    for (char& c : s) {
        c = conv[c];

        if (c == '.') {
            cout << "no" << '\n';
            return 0;
        }
    }

    reverse(s.begin(), s.end());
    ll m = stoll(s);

    if (!is_prime(n) || !is_prime(m)) {
        cout << "no" << '\n';
    }
    else {
        cout << "yes" << '\n';
    }

    return 0;
}
