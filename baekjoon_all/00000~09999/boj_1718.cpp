#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string line, key, secured_line;
    getline(cin, line);
    getline(cin, key);

    int line_len = line.length();
    int key_len = key.length();
    
    for (int i = 0; i < line_len; i++) {
        if (line[i] == ' ') {
            secured_line.push_back(' ');
            continue;
        }
        int n1 = line[i] - 'a';
        int n2 = key[i % key_len] - 'a';

        int n3 = (n1 - n2 + 25) % 26;
        char ch3 = 'a' + n3;
        secured_line.push_back(ch3);
    }

    cout << secured_line << '\n';

    return 0;
}