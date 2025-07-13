// Solve 2025-07-10

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

string num;

bool is_cute() {
    if (size(num) <= 1) {
        return true;
    }

    int a = num[0] - '0';
    int b = num[1] - '0';
    int diff = b - a;

    for (int i = 2; i < size(num); i++) {
        a = b;
        b = num[i] - '0';

        if (b - a != diff) {
            return false;
        }
    }

    return true;
}

void input() {
    cin >> num;
}

void pro() {
    if (is_cute()) {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << '\n';
    }
    else {
        cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << '\n';
    }
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
