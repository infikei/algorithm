// Solve 2023-10-11

#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 2; i++) {
        int t, f, s, p, c;
        cin >> t >> f >> s >> p >> c;

        int score = 6 * t + 3 * f + 2 * s + p + 2 * c;

        cout << score << ' ';
    }

    cout << '\n';

    return 0;
}
