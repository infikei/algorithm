// Solve 2023-08-18
// Update 2023-10-11

#include <iostream>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    int ans[2] = { n - 1, n };

    for (int i = 0; i < q; i++) {
        cout << ans[i & 1] << '\n';
    }

    cout << endl;

    return 0;
}
