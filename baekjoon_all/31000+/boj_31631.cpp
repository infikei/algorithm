// Solve 2025-05-31

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

int arr[5000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int i = 0;
    int j = n - 1;
    int num = n;

    while (true) {
        arr[j] = num;
        j--;
        num--;
        if (num == 0) break;

        arr[i] = num;
        i++;
        num--;
        if (num == 0) break;

        arr[i] = num;
        i++;
        num--;
        if (num == 0) break;

        arr[j] = num;
        j--;
        num--;
        if (num == 0) break;
    }

    for (i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    return 0;
}
