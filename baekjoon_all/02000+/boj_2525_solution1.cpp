// Solve 2022-06-02
// Update 2023-10-09

#include <iostream>
using namespace std;

int main() {
    int hour, minute, extra;
    cin >> hour >> minute >> extra;

    int ans = hour * 60 + minute + extra;

    cout << ans / 60 % 24 << ' ' << ans % 60 << '\n';

    return 0;
}
