// Solve 2026-06-14

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

int n, sqrt_n;
int arr[50000];
int bucket[240];

void init_bucket() {
    for (int i = 0; i <= sqrt_n; i++) {
        int i_bucket_begin = i * sqrt_n;
        int i_bucket_end = min(n, i_bucket_begin + sqrt_n);

        for (int j = i_bucket_begin; j < i_bucket_end; j++) {
            bucket[i] = max(bucket[i], arr[j]);
        }
    }
}

int get_max(int a, int b) {
    int mx = 0;
    int a_bucket = a / sqrt_n;
    int b_bucket = b / sqrt_n;

    if (a_bucket == b_bucket) {
        for (int i = a; i <= b; i++) {
            mx = max(mx, arr[i]);
        }

        return mx;
    }

    for (int i = a_bucket + 1; i < b_bucket; i++) {
        mx = max(mx, bucket[i]);
    }

    for (int i = a; i < a_bucket * sqrt_n + sqrt_n; i++) {
        mx = max(mx, arr[i]);
    }

    for (int i = b; i >= b_bucket * sqrt_n; i--) {
        mx = max(mx, arr[i]);
    }

    return mx;
}

int main() {
    FASTIO;

    int q;
    cin >> n >> q;
    sqrt_n = sqrt(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init_bucket();

    while (q-- > 0) {
        int a, b;
        cin >> a >> b;
        cout << get_max(a - 1, b - 1) << '\n';
    }

    return 0;
}
