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

        int quick_sum = 0, iter = 0;
        for (auto a : line) {
            iter++;
            if (a == ' ') continue;
            quick_sum += iter * (a - 'A' + 1);
        }

        cout << quick_sum << '\n';
    }

    return 0;
}