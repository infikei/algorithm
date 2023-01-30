#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, W, H, L;
    cin >> N >> W >> H >> L;

    int ans = min(N, (W / L) * (H / L));
    cout << ans << '\n';

    return 0;
}