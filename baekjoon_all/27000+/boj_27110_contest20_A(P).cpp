#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n, a[3], ans = 0;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        ans += min(n, a[i]);
    }
    cout << ans << '\n';

    return 0;
}