// Solve 2023-04-17
// Update 2025-02-26

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
    string s;
    cin >> n >> s;

    bool vitamin_str = false;

    for (int i = 1; i < n; i++) {
        string left = s.substr(0, i);
        string right = s.substr(n - i, i);
        int different_cnt = 0;

        for (int j = 0; j < i; j++) {
            if (left[j] != right[j]) {
                different_cnt++;

                if (different_cnt > 1) break;
            }
        }

        if (different_cnt == 1) {
            vitamin_str = true;
            break;
        }
    }

    if (vitamin_str) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}
