// Solve 2023-11-26
// Update 2024-07-01

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int fruits[200000];

    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int max_len = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            int cur_len = 0;

            for (int k = 0; k < n; k++) {
                if (fruits[k] == i || fruits[k] == j) {
                    cur_len++;
                }
                else {
                    max_len = max(max_len, cur_len);
                    cur_len = 0;
                }
            }

            max_len = max(max_len, cur_len);
        }
    }

    cout << max_len << '\n';

    return 0;
}
