// Solve 2024-08-03

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    int max_depart = -1;

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;

        if (s + t <= x && s > max_depart) {
            max_depart = s;
        }
    }

    cout << max_depart << '\n';

    return 0;
}
