// Solve 2025-11-05

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

int a[100000];
int b[100000];
vector<int> same;
vector<int> na;
vector<int> nb;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);
    int i = 0;
    int j = 0;

    while (i < n && j < n) {
        if (a[i] == b[j]) {
            same.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            na.push_back(a[i]);
            i++;
        }
        else {
            nb.push_back(b[j]);
            j++;
        }
    }

    while (i < n) {
        na.push_back(a[i]);
        i++;
    }

    while (j < n) {
        nb.push_back(b[j]);
        j++;
    }

    cout << size(same) << '\n';

    for (int x : same) cout << x << ' ';
    for (int x : na) cout << x << ' ';
    cout << '\n';

    for (int x : same) cout << x << ' ';
    for (int x : nb) cout << x << ' ';
    cout << '\n';

    return 0;
}
