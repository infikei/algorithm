// Solve 2023-12-21

#include <iostream>
using namespace std;

int main() {
    int n1, n2, n12;
    cin >> n1 >> n2 >> n12;

    int n = (n1 + 1) * (n2 + 1) / (n12 + 1) - 1;
    cout << n << '\n';

    return 0;
}
