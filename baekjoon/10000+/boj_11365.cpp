#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    while (true) {
        string input;
        getline(cin, input);
        if (input == "END") {
            break;
        }

        int input_sz = input.length();
        for (int i = input_sz - 1; i >= 0; i--) {
            cout << input[i];
        }
        cout << '\n';
    }

    return 0;
}