// Solve 2023-11-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    int max_black_line = 0, zebras_with_max_black_line = 0;

    for (int i = 0; i < n; i++) {
        string zebra;
        cin >> zebra;

        int black_line = 0;
        char prev = '0';

        for (int j = 0; j < l; j++) {
            if (prev == '0' && zebra[j] == '1') {
                black_line++;
            }

            prev = zebra[j];
        }

        if (black_line > max_black_line) {
            max_black_line = black_line;
            zebras_with_max_black_line = 1;
        }
        else if (black_line == max_black_line) {
            zebras_with_max_black_line++;
        }
    }

    cout << max_black_line << ' ' << zebras_with_max_black_line << '\n';

    return 0;
}
