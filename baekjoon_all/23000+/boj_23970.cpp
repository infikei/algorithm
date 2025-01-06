// Solve 2025-01-02

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

int n;
int a[10000];
int b[10000];

int solution() {
    int same_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            same_cnt++;
        }
    }

    if (same_cnt == n) {
        return 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                if (a[j] == b[j]) same_cnt--;
                if (a[j + 1] == b[j + 1]) same_cnt--;

                swap(a[j], a[j + 1]);

                if (a[j] == b[j]) same_cnt++;
                if (a[j + 1] == b[j + 1]) same_cnt++;

                if (same_cnt == n) return 1;
            }
        }
    }

    return 0;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    println(solution());

    return 0;
}
