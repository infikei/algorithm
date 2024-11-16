// Solve 2024-11-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

unordered_map<ll, ll> memo;

ll recur(ll k) {
    if (memo.find(k) != memo.end()) {
        return memo[k];
    }

    ll res = 0;
    ll blocks = k - 2;

    if (blocks % 3 == 0) {
        res = 2 + recur(blocks / 3) * 3;
    }
    else if (blocks % 3 == 1) {
        res = 2 + recur(blocks / 3) * 2 + recur(blocks / 3 + 1);
    }
    else {
        // 예를 들어, 2개를 들어낸 후 블럭 8개가 남았다면 (2, 3, 3)으로 나눌 수도 있고, (2, 2, 4)로 나눌 수도 있다.
        // 따라서 이 2가지 경우에 대해 각각 구한 후, 그 중 최댓값을 구해야 한다.
        ll res1 = recur(blocks / 3) + recur(blocks / 3 + 1) * 2;
        ll res2 = recur(blocks / 3) * 2 + recur(blocks / 3 + 2);
        res = 2 + max(res1, res2);
    }

    memo[k] = res;
    return res;
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    memo[1] = 0;
    memo[2] = 0;
    memo[3] = 1;
    memo[4] = 1;

    println(recur(n));

    return 0;
}
