// Solve 2024-11-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int a[500000];
int b[500000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (b[0] == 0) {
        println(-1);
        return 0;
    }

    a[0] = b[0];
    ll a_sum = 0;
    bool flag = true;

    for (int i = 1; i < n; i++) {
        a_sum += a[i - 1];

        // 첫번째 시도

        a[i] = b[i];
        ll new_bi = a[i];

        if (new_bi * i < a_sum) {
            new_bi--;
        }

        if (a[i] >= 1 && new_bi == b[i]) {
            continue;
        }

        // 두번째 시도

        a[i] = b[i] + 1;
        new_bi = a[i];

        if (new_bi * i < a_sum) {
            new_bi--;
        }

        if (a[i] >= 1 && new_bi == b[i]) {
            continue;
        }

        // 모든 시도가 실패하면 불가능한 경우이다.

        flag = false;
        break;
    }

    if (!flag) {
        println(-1);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printw(a[i]);
    }

    cout << '\n';

    return 0;
}
