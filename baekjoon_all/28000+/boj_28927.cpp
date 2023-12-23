// Solve 2023-12-23

#include <iostream>
using namespace std;

int main() {
    int t1, e1, f1;
    cin >> t1 >> e1 >> f1;

    int t2, e2, f2;
    cin >> t2 >> e2 >> f2;

    int x1 = t1 * 3 + e1 * 20 + f1 * 120;
    int x2 = t2 * 3 + e2 * 20 + f2 * 120;

    if (x1 > x2) cout << "Max\n";
    else if (x1 < x2) cout << "Mel\n";
    else cout << "Draw\n";

    return 0;
}
