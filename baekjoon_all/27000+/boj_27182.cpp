// Solve 2023-09-29
// Update 2023-12-23

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    cout << (n >= 8 ? n - 7 : m + 7) << '\n';

    return 0;
}
