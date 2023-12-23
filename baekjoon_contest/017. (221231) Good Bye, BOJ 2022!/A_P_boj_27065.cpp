// Solve 2023-01-01
// Update 2023-12-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int number_type(int k) {
    int sum = 0;

    for (int i = 1, ie = sqrt(k); i <= ie; i++) {
        if (k % i != 0) continue;

        int ii = k / i;
        sum += i;

        if (i != ii) sum += ii;
    }

    sum -= k;

    if (sum < k) return -1; // 부족수
    if (sum > k) return 1; // 과잉수
    return 0; // 완전수
}

int check(int k) {
    if (number_type(k) < 1) return 0;

    for (int i = 2, ie = sqrt(k); i <= ie; i++) {
        if (k % i != 0) continue;

        int ii = k / i;

        if (number_type(i) > 0) return 0;
        if (number_type(ii) > 0) return 0;
    }

    return 1;
}

int main() {
    FASTIO;

    string ans_str[2] = { "BOJ 2022", "Good Bye" };

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int ans = check(n);
        cout << ans_str[ans] << '\n';
    }

    return 0;
}
