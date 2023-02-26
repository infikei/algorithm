// Solve 2021-12-18
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++) {
        cout << n << " * " << i << " = " << n * i << '\n';
    }

    return 0;
}