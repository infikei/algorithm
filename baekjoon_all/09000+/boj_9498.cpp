// Solve 2021-12-18
// Update 2023-02-26

#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;

    if (score >= 90) {
        cout << "A\n";
    }
    else if (score >= 80) {
        cout << "B\n";
    }
    else if (score >= 70) {
        cout << "C\n";
    }
    else if (score >= 60) {
        cout << "D\n";
    }
    else {
        cout << "F\n";
    }

    return 0;
}