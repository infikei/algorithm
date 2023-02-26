// Solve 2021-12-18
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << a * (b % 10) << '\n';
    cout << a * (b / 10 % 10) << '\n';
    cout << a * (b / 100) << '\n';
    cout << a * b << '\n';

    return 0;
}