// Solve 2023-06-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[500001], tmp[500001];
ll ans;

void merge(int s, int mid, int e) {
    int i = s, j = mid + 1, k = s;
    int cnt = 0;
    while (k <= e) {
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
        k++;
    }

    for (k = s; k <= e; k++) {
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
