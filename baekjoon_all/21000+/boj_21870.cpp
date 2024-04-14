// Solve 2024-04-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Pair{
    int beauty, gcd;

    Pair(int beauty, int gcd) : beauty(beauty), gcd(gcd) {}
};

int arr[200000];

int calc_gcd(int a, int b) {
    int r = a % b;

    if (a % b == 0) return b;

    return calc_gcd(b, r);
}

Pair recur(int left, int right) {
    if (left + 1 == right) {
        return Pair(arr[left], arr[left]);
    }

    if (left + 2 == right) {
        return Pair(arr[left] + arr[left + 1], calc_gcd(arr[left], arr[left + 1]));
    }

    int mid = (left + right) / 2;
    Pair left_res = recur(left, mid);
    Pair right_res = recur(mid, right);
    int nbeauty = max(left_res.beauty + right_res.gcd, left_res.gcd + right_res.beauty);
    int ngcd = calc_gcd(left_res.gcd, right_res.gcd);
    return Pair(nbeauty, ngcd);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Pair res = recur(0, n);
    cout << res.beauty << '\n';

    return 0;
}
