// Solve 2025-11-15

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

int arr[5000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int s = 0;
    int e = 1;

    while (e < n) {
        bool palindrome = true;
        int i = s;
        int j = e;

        while (i < j) {
            if (arr[i] != arr[j]) {
                palindrome = false;
                break;
            }

            i++;
            j--;
        }

        if (palindrome) {
            cnt++;
            s = e + 1;
            e = s + 1;
        }
        else {
            e += 2;
        }
    }

    if (s == n) {
        cout << cnt << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
