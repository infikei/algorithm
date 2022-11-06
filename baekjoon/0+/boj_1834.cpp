#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    ll N;
    cin >> N;

    ll ans = (N - 1) * N / 2 * (N + 1);
    cout << ans << '\n';

    return 0;
}