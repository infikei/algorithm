// Solve 2023-10-10

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word;
    cin >> word;

    reverse(word.begin(), word.end());

    cout << word << '\n';

    return 0;
}
