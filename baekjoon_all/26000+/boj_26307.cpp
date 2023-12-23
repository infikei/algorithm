// Solve 2023-12-23

#include <iostream>
using namespace std;

int main() {
    int hh, mm;
    cin >> hh >> mm;

    int ans = (hh - 9) * 60 + mm;
    cout << ans << '\n';

    return 0;
}
