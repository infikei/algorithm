// Solve 2025-09-24

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

int n, k;
int a[10001];
int cnt = 0;

void print_a() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';
}

int partition(int l, int r) {
    int pivot = a[r];
    int i = l;

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);

            if (++cnt == k) {
                print_a();
            }

            i++;
        }
    }

    if (i != r) {
        swap(a[i], a[r]);

        if (++cnt == k) {
            print_a();
        }
    }

    return i;
}

void quick_sort(int l = 1, int r = n) {
    if (l < r) {
        int mid = partition(l, r);
        quick_sort(l, mid - 1);
        quick_sort(mid + 1, r);
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    quick_sort();

    if (cnt < k) {
        cout << -1 << '\n';
    }

    return 0;
}
