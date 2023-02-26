// Solve 2021-12-18
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << (a + b) % c << '\n';
    cout << (a % c + b % c) % c << '\n';
    cout << a * b % c << '\n';
    cout << (a % c) * (b % c) % c << '\n';

    return 0;
}