#include <iostream>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

const ll MOD = 1000000007;
unordered_map<int, ll> hs;

int main() {
    fastio;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        hs[x]++;
    }

    ll ans = 1;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        ans = ans * (it->second + 1) % MOD;
    }
    ans--;
    cout << ans << '\n';

    return 0;
}