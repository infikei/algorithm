// Solve 2025-06-19

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

string s;

void input() {
    cin >> s;
}

void pro() {
    int depth = 0;
    int left = 0;
    int right = 0;

    for (int i = 0; i < size(s); i++) {
        if (s[i] == '(') {
            depth++;
            left++;
        }
        else {
            depth--;
            right++;
        }

        if (depth == -1) {
            cout << right << '\n';
            return;
        }
        else if (depth == 0) {
            left = 0;
        }
    }

    cout << left << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
