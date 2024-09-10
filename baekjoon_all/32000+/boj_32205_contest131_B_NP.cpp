// Solve 2024-09-08

#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    unordered_set<int> hs;

    for (int i = 0; i < n * 3; i++) {
        int x;
        cin >> x;

        if (hs.find(x) != hs.end()) {
            ans = 1;
            break;
        }

        hs.insert(x);
    }

    cout << ans << '\n';

    return 0;
}
