// Solve 2021-12-18
// Update 2023-08-02

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "<\n";
    }
    else if (a > b) {
        cout << ">\n";
    }
    else {
        cout << "==\n";
    }

    return 0;
}
