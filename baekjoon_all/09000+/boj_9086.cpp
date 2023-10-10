// Solve 2022-06-06
// Update 2023-10-10

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;

        cout << s[0] << s.back() << '\n';
    }

    return 0;
}
