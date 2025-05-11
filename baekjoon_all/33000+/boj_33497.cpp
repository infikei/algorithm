// Solve 2025-05-11

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

int arr[100][2];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<string> timetable(n, string(m, '.'));
    int x_pos = 0;

    for (int y = 0; y < m; y++) {
        cin >> arr[y][0] >> arr[y][1];

        if (arr[y][0] + arr[y][1] > n) {
            cout << "NO" << '\n';
            return 0;
        }

        for (int i = n - arr[y][0] - arr[y][1]; i > 0; i--) {
            if (x_pos >= n) {
                continue;
            }

            timetable[x_pos][y] = 'X';
            x_pos++;
        }
    }

    if (x_pos < n) {
        cout << "NO" << '\n';
        return 0;
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (timetable[x][y] == 'X') continue;

            if (arr[y][0] > 0) {
                timetable[x][y] = '+';
                arr[y][0]--;
            }
            else {
                timetable[x][y] = '-';
            }
        }
    }

    cout << "YES" << '\n';

    for (int x = 0; x < n; x++) {
        cout << timetable[x] << '\n';
    }

    return 0;
}
