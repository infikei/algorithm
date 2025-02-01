// Solve 2025-01-31

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

int arr[100001];
int prefix_sum[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll ans = 0;
    ll cur_sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ans += cur_sum * x;
        cur_sum += x;
    }

    println(ans);

    return 0;
}
