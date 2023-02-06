#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string line;
    getline(cin, line);

    string target = "UCPC";
    int cur = 0;

    for (int i = 0; i < (int)line.length(); i++) {
        if (line[i] == target[cur]) {
            cur++;
            if (cur == 4) {
                break;
            }
        }
    }

    if (cur == 4) {
        cout << "I love UCPC\n";
    }
    else {
        cout << "I hate UCPC\n";
    }

    return 0;
}