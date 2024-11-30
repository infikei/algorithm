// Solve 2024-01-01

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        int n, m;
        cin >> n >> m;

        int a[20], b[20];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }

        int answer = 0;

        for (int i = 0; i < min(n, m); i++) {
            answer += a[i] * b[i];
        }

        if (n < m) {
            int diff = m - n;

            for (int d = 1; d <= diff; d++) {
                int value = 0;

                for (int i = 0; i < n; i++) {
                    value += a[i] * b[i + d];
                }

                if (value > answer) {
                    answer = value;
                }
            }
        }
        else if (n > m) {
            int diff = n - m;

            for (int d = 1; d <= diff; d++) {
                int value = 0;

                for (int i = 0; i < m; i++) {
                    value += a[i + d] * b[i];
                }

                if (value > answer) {
                    answer = value;
                }
            }
        }

        cout << "#" << test_case << " " << answer << '\n';
    }

    return 0;
}
