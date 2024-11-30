// Solve 2024-01-01

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int a, b;
    cin >> a >> b;

    if ((a - b + 3) % 3 == 1) {
        cout << "A" << '\n';
    }
    else {
        cout << "B" << '\n';
    }

    return 0;
}
