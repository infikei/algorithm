// Solve 2023-06-08
// Update 2025-08-03

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

int arr[500001];
int tmp[500001];
ll ans;

void merge(int s, int mid, int e) {
    int cnt = 0;
    int i = s;
    int j = mid + 1;

    for (int k = s; k <= e; k++) {
        if (j > e) {
            ans += cnt;
            tmp[k] = arr[i];
            i++;
        }
        else if (i > mid || arr[i] > arr[j]) {
            cnt++;
            tmp[k] = arr[j];
            j++;
        }
        else {
            ans += cnt;
            tmp[k] = arr[i];
            i++;
        }
    }

    for (int k = s; k <= e; k++) {
        arr[k] = tmp[k];
    }
}

void merge_sort(int s, int e) {
    if (s < e) {
        int mid = (s + e) >> 1;
        merge_sort(s, mid);
        merge_sort(mid + 1, e);
        merge(s, mid, e);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    merge_sort(1, n);
    cout << ans << '\n';
    return 0;
}
