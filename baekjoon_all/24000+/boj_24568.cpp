// Solve 2023-10-11

#include <iostream>
using namespace std;

int main() {
    int regular, small;
    cin >> regular >> small;

    int ans = regular * 8 + small * 3 - 28;

    cout << ans << '\n';

    return 0;
}
