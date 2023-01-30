#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

string sentence, encoding_sentence, encoding_key;

int main() {
    fastio;

    cin >> sentence >> encoding_sentence;
    int sentence_len = sentence.length();

    for (int i = 0; i < sentence_len; i++) {
        char ch = (encoding_sentence[i] - sentence[i] + 25) % 26 + 'A';
        encoding_key.push_back(ch);
    }

    for (int key_len = 1; key_len <= sentence_len / 2; key_len++) {
        if (encoding_key[key_len] != encoding_key[0]) {
            continue;
        }
        if (sentence_len % key_len != 0) {
            continue;
        }
        bool check = true;
        for (int i = 0; i < sentence_len; i++) {
            if (encoding_key[i] != encoding_key[i % key_len]) {
                check = false;
                break;
            }
        }
        if (check) {
            encoding_key = encoding_key.substr(0, key_len);
            break;
        }
    }

    cout << encoding_key << '\n';

    return 0;
}