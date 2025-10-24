// Solve 2025-10-21

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

int line[6][8] = {
    {1, 3, 5, 7, 9, 11, 24, 22},
    {2, 4, 6, 8, 10, 12, 23, 21},
    {1, 2, 18, 20, 12, 11, 15, 13},
    {3, 4, 17, 19, 10, 9, 16, 14},
    {13, 14, 5, 6, 17, 18, 21, 22},
    {15, 16, 7, 8, 19, 20, 23, 24}
};

void rotate1(vector<int>& cube, int idx) {
    for (int j = 0; j <= 4; j += 2) {
        swap(cube[line[idx][j]], cube[line[idx][j + 2]]);
        swap(cube[line[idx][j + 1]], cube[line[idx][j + 3]]);
    }
}

void rotate2(vector<int>& cube, int idx) {
    for (int j = 4; j >= 0; j -= 2) {
        swap(cube[line[idx][j]], cube[line[idx][j + 2]]);
        swap(cube[line[idx][j + 1]], cube[line[idx][j + 3]]);
    }
}

bool check(vector<int>& cube) {
    for (int i = 1; i <= 21; i += 4) {
        for (int j = i + 1; j <= i + 3; j++) {
            if (cube[i] != cube[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FASTIO;

    vector<int> cube(25);

    for (int i = 1; i <= 24; i++) {
        cin >> cube[i];
    }

    for (int i = 0; i < 6; i++) {
        vector<int> tmp = cube;
        rotate1(tmp, i);

        if (check(tmp)) {
            cout << 1 << '\n';
            return 0;
        }

        tmp = cube;
        rotate2(tmp, i);

        if (check(tmp)) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}
