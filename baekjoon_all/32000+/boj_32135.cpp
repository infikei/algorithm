// Solve 2025-03-07

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

int arr[500];

void init_arr(int n) {
    int mid = (n - 1) / 2;

    arr[0] = 3;
    arr[mid] = 5;
    arr[mid + 1] = 4;
    arr[n - 1] = 6;

    int num = 1;

    for (int i = 1; i < mid; i++) {
        arr[i] = num;
        num += 2;

        if (num == 3) num += 4;
    }

    num = 2;

    for (int i = mid + 2; i < n - 1; i++) {
        arr[i] = num;
        num += 2;

        if (num == 4) num += 4;
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    init_arr(n);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            // cout << arr[(x + y) % n] << ' ';
            cout << arr[(x + y >= n) ? (x + y - n) : (x + y)] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
