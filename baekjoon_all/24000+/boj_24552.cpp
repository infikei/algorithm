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
int memo[100001];

void reverse_parentheses() {
    reverse(s.begin(), s.end());

    for (int i = 0; i < size(s); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else {
            s[i] = '(';
        }
    }
}

void input() {
    cin >> s;
}

void pro() {
    for (int i = 1; i <= size(s); i++) {
        if (s[i - 1] == '(') {
            memo[i] = memo[i - 1] + 1;
        }
        else {
            memo[i] = memo[i - 1] - 1;
        }
    }

    if (memo[size(s)] == -1) {
        reverse_parentheses();
        pro();
        return;
    }

    int cnt = 0;

    for (int i = 1; i <= size(s); i++) {
        if (s[i - 1] == '(') {
            cnt++;
        }
        else if (memo[i] == 0) {
            cnt = 0;
        }
    }

    cout << cnt << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
