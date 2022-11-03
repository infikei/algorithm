#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
int numbers[50];

int solve() {
    if (N == 1) {
        return 12345678;
    }
    if (numbers[0] == numbers[1]) {
        for (int i = 2; i < N; i++) {
            if (numbers[0] != numbers[i]) {
                return 87654321;
            }
        }
        return numbers[0];
    }
    if (N == 2) {
        return 12345678;
    }
    if ((numbers[2] - numbers[1]) % (numbers[1] - numbers[0]) != 0) {
        return 87654321;
    }
    int a = (numbers[2] - numbers[1]) / (numbers[1] - numbers[0]);
    int b = numbers[1] - a * numbers[0];
    for (int i = 3; i < N; i++) {
        if (numbers[i] != numbers[i - 1] * a + b) {
            return 87654321;
        }
    }
    return numbers[N - 1] * a + b;
}

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int ans = solve();

    if (ans == 12345678) {
        cout << 'A' << '\n';
    }
    else if (ans == 87654321) {
        cout << 'B' << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}