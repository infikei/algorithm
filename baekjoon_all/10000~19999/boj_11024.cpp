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
        int ans = 0;
        while (getline(ss, word, ' ')) {
            ans += stoi(word);
        }

        cout << ans << '\n';
    }

    return 0;
}