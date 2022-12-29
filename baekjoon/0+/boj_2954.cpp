#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    fastio;

    string sentence_in;
    getline(cin, sentence_in);

    string sentence_out;
    int i_end = sentence_in.length();
    for (int i = 0; i < i_end; i++) {
        sentence_out.push_back(sentence_in[i]);
        for (int j = 0; j < 5; j++) {
            if (sentence_in[i] == aeiou[j]) {
                i += 2;
                break;
            }
        }
    }
    cout << sentence_out << '\n';

    return 0;
}