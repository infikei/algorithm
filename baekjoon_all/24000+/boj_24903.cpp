// Solve 2023-08-18

#include <iostream>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    int ans[2] = { n - 1, n };

    cout << ans[0];
    for (int i = 1; i < q; i++) {
        cout << '\n' << ans[i & 1];
    }
    cout << endl;

    return 0;
}
