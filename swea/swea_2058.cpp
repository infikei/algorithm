// Solve 2024-01-01

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string n;
    cin >> n;

    int answer = 0;

    for (char digit : n) {
        answer += digit - '0';
    }

    cout << answer << '\n';

    return 0;
}
