// Solve 2024-09-22

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int cur = m;

    for (int i = 0; i < n; i++) {
        cur += m;
        cout << cur << ' ';
    }

    cout << '\n';

    return 0;
}
