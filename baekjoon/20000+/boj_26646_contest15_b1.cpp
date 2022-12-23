#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int N;
ll ans;
vector<ll> H;

int main() {
    fastio;

    cin >> N;
    H.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    ll garo, sero;
    for (int i = 1; i < N; i++) {
        garo = H[i] + H[i - 1];
        sero = H[i] - H[i - 1];
        ans += (garo * garo + sero * sero);
    }

    cout << ans << '\n';

    return 0;
}