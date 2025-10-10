// Solve 2025-10-10

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

string name[3] = {"Joffrey", "Robb", "Stannis"};

int main() {
    FASTIO;

    int arr[3];
    int mx = 0;

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 3; i++) {
        int v;
        cin >> v;
        arr[i] *= v;
        mx = max(mx, arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (arr[i] == mx) {
            cout << name[i] << ' ';
        }
    }

    cout << '\n';
    return 0;
}
