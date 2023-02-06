#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; t++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;

        getline(ss, word, ' ');
        double ans = stod(word);

        while (getline(ss, word, ' ')) {
            if (word == "@") {
                ans *= 3;
            }
            else if (word == "%") {
                ans += 5;
            }
            else if (word == "#") {
                ans -= 7;
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << ans << '\n';
    }

    return 0;
}