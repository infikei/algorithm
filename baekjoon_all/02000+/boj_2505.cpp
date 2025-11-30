// Solve 2025-11-29

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

bool solution1(int n, vector<int>& v) {
    int a = 1, b = 1;

    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            for (int j = i + 1; j <= n; j++) {
                if (v[j] == i) {
                    a = i;
                    b = j;
                    break;
                }
            }

            break;
        }
    }

    reverse(v.begin() + a, v.begin() + (b + 1));
    int c = 1, d = 1;

    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            for (int j = i + 1; j <= n; j++) {
                if (v[j] == i) {
                    c = i;
                    d = j;
                    break;
                }
            }

            break;
        }
    }

    reverse(v.begin() + c, v.begin() + (d + 1));

    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            return false;
        }
    }

    cout << a << ' ' << b << '\n';
    cout << c << ' ' << d << '\n';
    return true;
}

bool solution2(int n, vector<int>& v) {
    int a = 1, b = 1;

    for (int i = n; i >= 1; i--) {
        if (v[i] != i) {
            for (int j = i - 1; j >= 1; j--) {
                if (v[j] == i) {
                    a = j;
                    b = i;
                    break;
                }
            }

            break;
        }
    }

    reverse(v.begin() + a, v.begin() + (b + 1));
    int c = 1, d = 1;

    for (int i = n; i >= 1; i--) {
        if (v[i] != i) {
            for (int j = i - 1; j >= 1; j--) {
                if (v[j] == i) {
                    c = j;
                    d = i;
                    break;
                }
            }

            break;
        }
    }

    reverse(v.begin() + c, v.begin() + (d + 1));

    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            return false;
        }
    }

    cout << a << ' ' << b << '\n';
    cout << c << ' ' << d << '\n';
    return true;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> v1, v2;
    v1.push_back(0);
    v2.push_back(0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
        v2.push_back(x);
    }

    if (solution1(n, v1)) {
        return 0;
    }

    solution2(n, v2);
    return 0;
}
