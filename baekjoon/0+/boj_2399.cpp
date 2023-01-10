#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

const int MAX_N = 10000;
ll arr[MAX_N];

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += abs(arr[i] - arr[j]);
        }
    }

    ans *= 2;
    cout << ans << '\n';

    return 0;
}