// Solve 2024-01-01

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        int answer = -1;

        for (int i = 0; i < 10; i++) {
            int num;
            cin >> num;

            if (num > answer) {
                answer = num;
            }
        }

        cout << "#" << test_case << " " << answer << '\n';
    }

    return 0;
}
