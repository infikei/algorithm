#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll N, A, B, PA, PB, A_cnt, B_cnt;

int main() {
    fastio;

    cin >> N >> A >> PA >> B >> PB;

    ll max_val = 0;
    for (ll a_cnt = N / PA; a_cnt >= 0; a_cnt--) {
        ll b_cnt = (N - a_cnt * PA) / PB;
        ll val = A * a_cnt + B * b_cnt;
        if (val > max_val) {
            max_val = val;
            A_cnt = a_cnt;
            B_cnt = b_cnt;
        }
    }

    cout << A_cnt << ' ' << B_cnt << '\n';

    return 0;
}