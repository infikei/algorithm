// Solve 2025-04-30

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

bool has_more_lower_alphabet_than_upper(string &s) {
    int lower_cnt = 0;
    int upper_cnt = 0;

    for (char &c : s) {
        if (c >= 'a' && c <= 'z') lower_cnt++;
        else if (c >= 'A' && c <= 'Z') upper_cnt++;
    }

    return lower_cnt >= upper_cnt;
}

bool is_all_digit(string &s) {
    for (char &c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    while (n-- > 0) {
        string s;
        cin >> s;

        if (s.size() <= 10 && has_more_lower_alphabet_than_upper(s) && !is_all_digit(s)) {
            cout << s << '\n';
        }
    }

    return 0;
}
