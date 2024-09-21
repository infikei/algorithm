// Solve 2024-09-16

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << n * (n + 1) * (n + 2) / 2 << '\n';

    return 0;
}
