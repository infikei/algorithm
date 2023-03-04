// Solve 2022-09-09
// Update 2023-03-04

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 100000;
int arr[MAX_N];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int prev = -1001;
    for (int i = 0; i < n; i++) {
        if (arr[i] == prev) {
            continue;
        }
        prev = arr[i];
        cout << prev << ' ';
    }
    cout << '\n';

    return 0;
}