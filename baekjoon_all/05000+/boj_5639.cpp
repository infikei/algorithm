// Solve 2023-02-14
// Update 2023-07-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[10000];

void print(int s, int e) {
    if (s > e) return;

    int mid = upper_bound(arr + (s + 1), arr + (e + 1), arr[s]) - arr;
    print(s + 1, mid - 1);
    print(mid, e);
    cout << arr[s] << '\n';
}

int main() {
    FASTIO;

    int n = 0, x;
    while (cin >> x) {
        arr[n] = x;
        n++;
    }

    print(0, n - 1);

    return 0;
}
