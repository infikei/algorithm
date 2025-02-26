// Solve 2025-02-26

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
    string pars;
    cin >> n >> pars;

    int cnt_open = 0;
    int cnt_close = 0;

    for (char &p : pars) {
        if (p == '(') {
            cnt_open++;
        }
        else if (p == ')') {
            cnt_close++;
        }
    }

    int cnt_open_need = n / 2 - cnt_open;

    for (int i = 0; i < n; i++) {
        if (pars[i] == 'G') {
            if (cnt_open_need > 0) {
                pars[i] = '(';
                cnt_open_need--;
            }
            else {
                pars[i] = ')';
            }
        }
    }

    cout << pars << '\n';

    return 0;
}
