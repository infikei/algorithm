// Solve 2025-02-28

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

    string s;
    cin >> s;

    int cur_time[3];

    for (int i = 0; i <= 2; i++) {
        cur_time[i] = stoi(s.substr(i * 3, 2));
    }

    int cnt = 0;

    for (int i = 0; i <= 2; i++) {
        if (cur_time[i] < 1 || cur_time[i] > 12) continue;

        for (int j = 0; j <= 2; j++) {
            if (j == i) continue;
            int k = 3 - i - j;

            if (cur_time[j] > 59 || cur_time[k] > 59) continue;

            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
