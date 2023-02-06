#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll N;
vector<ll> vec;

int main() {
    fastio;

    cin >> N;
    vec.assign(N + 1, 0);
    for (ll i = 1; i <= N; i++) {
        cin >> vec[i];
    }

    ll pre = 0;
    for (ll i = 1; i <= N; i++) {
        ll now = vec[i] * i;
        cout << now - pre << ' ';
        pre = now;
    }
    cout << '\n';

    return 0;
}