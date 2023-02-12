// Solve 2023-02-12

#include <iostream>
using namespace std;

int main() {
    double a = 100000000000;
    long long b = 100000000000;
    float c = 100000000000;

    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    }
    else {
        cout << "false" << '\n';
    }

    return 0;
}