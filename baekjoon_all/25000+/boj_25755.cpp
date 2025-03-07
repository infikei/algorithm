// Solve 2025-03-06

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

string reversed_digit = "015??2??8?";
int arr[20][20];

int main() {
    FASTIO;

    char direction;
    int n;
    cin >> direction >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> arr[x][y];
        }
    }

    if (direction == 'L' || direction == 'R') {
        for (int x = 0; x < n; x++) {
            for (int y = n - 1; y >= 0; y--) {
                cout << reversed_digit[arr[x][y]] << ' ';
            }

            cout << '\n';
        }
    }
    else {
        for (int x = n - 1; x >= 0; x--) {
            for (int y = 0; y < n; y++) {
                cout << reversed_digit[arr[x][y]] << ' ';
            }

            cout << '\n';
        }
    }

    return 0;
}
