#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string word;
    cin >> word;
    int word_len = word.length();

    bool check = true;

    for (int i = 0; i < word_len / 2; i++) {
        if (word[i] != word[word_len - 1 - i]) {
            check = false;
            break;
        }
    }

    cout << check << '\n';

    return 0;
}