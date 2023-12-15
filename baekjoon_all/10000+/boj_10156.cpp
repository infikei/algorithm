// Solve 2022-06-25
// Update 2023-12-15

#include <iostream>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    cout << max(0, k * n - m) << '\n';

    return 0;
}
