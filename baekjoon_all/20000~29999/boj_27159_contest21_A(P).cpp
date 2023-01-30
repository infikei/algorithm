#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n, ans, arr[33];

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ans = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] + 1 != arr[i]) {
            ans += arr[i];
        }
    }
    cout << ans << '\n';

    return 0;
}