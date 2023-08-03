// Solve 2021-12-18
// Update 2023-08-02

#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    if (year % 400 == 0 || year % 4 == 0 && year % 100 > 0) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
