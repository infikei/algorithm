// Solve 2022-06-07
// Update 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int calc_gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return calc_gcd(b, r);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    // 들어온 값들의 차이들의 최대공약수를 구해야 함
    // 이때 비교하는 순서는 결과에 영향을 주지 않으므로 그냥 들어오는 대로 비교함
    int x0, x;
    cin >> x0 >> x;
    int ans = abs(x - x0);

    for (int i = 2; i < n; i++) {
        cin >> x;
        ans = calc_gcd(abs(x - x0), ans);
    }

    // 약수 검사 시 ans / 2까지만 검사해서 시간 단축
    for (int m = 2, me = ans / 2; m <= me; m++) {
        if (ans % m == 0) {
            cout << m << ' ';
        }
    }

    cout << ans << '\n';

    return 0;
}
