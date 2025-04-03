// Solve 2025-04-03

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

int n;
int arr[50];

bool solution() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((arr[i] - arr[j]) % arr[k] != 0) {
                    return false;
                }

                if ((arr[i] - arr[k]) % arr[j] != 0) {
                    return false;
                }

                if ((arr[j] - arr[k]) % arr[i] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool ans = solution();

    cout << (ans ? "yes" : "no") << '\n';

    return 0;
}
