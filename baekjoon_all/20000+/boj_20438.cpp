// Solve 2025-04-28

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

int arr[5003];

int main() {
    FASTIO;

    int n, k, q, m;
    cin >> n >> k >> q >> m;

    while (k-- > 0) {
        int sleeping_num;
        cin >> sleeping_num;

        arr[sleeping_num] = -1;
    }

    while (q-- > 0) {
        int num;
        cin >> num;

        if (arr[num] == -1) continue;

        for (int j = num; j <= n + 2; j += num) {
            if (arr[j] == 0) {
                arr[j] = 1;
            }
        }
    }

    for (int i = 3; i <= n + 2; i++) {
        if (arr[i] == 1) arr[i] = 0;
        else arr[i] = 1;

        arr[i] += arr[i - 1];
    }

    while (m-- > 0) {
        int s, e;
        cin >> s >> e;

        cout << arr[e] - arr[s - 1] << '\n';
    }

    return 0;
}
