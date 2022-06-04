#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    char ch;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ch;
        sum += (ch - '0');
    }

    cout << sum << "\n";

    return 0;
}