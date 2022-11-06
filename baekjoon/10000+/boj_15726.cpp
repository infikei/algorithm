#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    int A, B, C;
    cin >> A >> B >> C;

    ll ans = (ll)A * max(B, C) / min(B, C);
    cout << ans << '\n';

    return 0;
}