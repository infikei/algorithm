#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int location;

    cin >> input;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        location = input.find(ch);
        cout << location << " ";
    }

    return 0;
}