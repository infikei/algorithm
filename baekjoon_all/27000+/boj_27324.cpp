// Solve 2023-12-24

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << (n / 10 == n % 10 ? 1 : 0) << '\n';

    return 0;
}
