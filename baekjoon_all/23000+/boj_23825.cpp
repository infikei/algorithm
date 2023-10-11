// Solve 2022-11-02
// Update 2023-10-11

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = min(n / 2, m / 2);

    cout << ans << '\n';

    return 0;
}
