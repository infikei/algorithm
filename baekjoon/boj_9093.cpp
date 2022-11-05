#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string line;
        getline(cin, line);
        while (line == "") {
            getline(cin, line);
        }

        stringstream ss(line);
        string word;
        while (getline(ss, word, ' ')) {
            reverse(word.begin(), word.end());
            cout << word << ' ';
        }
        cout << '\n';
    }

    return 0;
}