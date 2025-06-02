// Solve 2025-05-31

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll get_gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

ll solution(int n, vector<pll>& logs) {
    ll m = -1;
    ll balance = 0;

    // 자동 충전 금액의 최대 공약수로 m 값을 계산한다.
    for (pll& log : logs) {
        balance += log.first;

        if (balance >= 0 && balance != log.second) {
            return -1;
        }

        if (balance < 0) {
            ll to_charge = log.second - balance;

            if (m == -1) {
                m = to_charge;
            }
            else {
                m = get_gcd(m, to_charge);
            }

            balance = log.second;
        }
    }

    // 자동 충전이 한번도 이루어지지 않은 경우 임의의 값을 반환한다.
    if (m == -1) return 1;

    // 구한 m 값으로 전체 로그를 검산한다.
    balance = 0;

    for (pll& log : logs) {
        balance += log.first;

        if (balance < 0) {
            ll to_charge = (-balance - 1 + m) / m * m; // (-balance) 이상인 m의 배수 중 최솟값
            balance += to_charge;

            if (balance != log.second) {
                return -1;
            }
        }
    }

    return m;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<pll> logs(n);

    for (pll& log : logs) {
        cin >> log.first >> log.second;
    }

    cout << solution(n, logs) << '\n';

    return 0;
}
