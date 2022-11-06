#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    ll ans = (ll)N * M / 2;
    cout << ans << '\n';

    return 0;
}