#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        if (input == "") getline(cin, input);

        bool check[26] = {false};
        for (auto a : input) {
            if (a >= 'a' && a <= 'z') check[a - 'a'] = true;
            else if (a >= 'A' && a <= 'Z') check[a - 'A'] = true;
        }

        string missing_alphabet = "";
        for (int i = 0; i < 26; i++) {
            if (!check[i]) missing_alphabet.push_back('a' + i);
        }

        cout << (missing_alphabet == "" ? "pangram" : "missing " + missing_alphabet) << '\n';
    }

    return 0;
}