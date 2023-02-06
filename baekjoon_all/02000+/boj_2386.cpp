#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    while (true) {
        string line;
        getline(cin, line);
        if (line == "#") break;

        char c = line[0];
        char c2 = c - 'a' + 'A';
        line = line.substr(2);
        int cnt = 0;

        for (auto a : line) {
            if (a == c || a == c2) cnt++;
        }

        cout << c << ' ' << cnt << '\n';
    }

    return 0;
}