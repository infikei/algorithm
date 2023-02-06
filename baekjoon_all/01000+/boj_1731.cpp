#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int main() {
    fastio;

    const int MAX_N = 50;
    int n;
    ll arr[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    if (arr[0] + arr[2] == arr[1] * 2) {
        ans = arr[n - 1] * 2 - arr[n - 2];
    }
    else {
        ans = arr[n - 1] * arr[1] / arr[0];
    }

    cout << ans << '\n';

    return 0;
}