#include <iostream>
#include <sstream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N;

int main() {
    fastio;

    cin >> N;

    string input, output, word;
    for (int i = 0; i < N; i++) {
        getline(cin, input);
        if (input == "") getline(cin, input);

        stringstream ss(input);
        getline(ss, word, ' ');
        output = "god";
        while (getline(ss, word, ' ')) output += word;

        cout << output << '\n';
    }

    return 0;
}