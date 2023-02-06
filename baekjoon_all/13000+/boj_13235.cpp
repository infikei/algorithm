#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string s;
    cin >> s;

    int s_len = s.length();
    bool is_palindrome = true;

    for (int i = 0; i < s_len / 2; i++) {
        if (s[i] != s[s_len - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) cout << "true\n";
    else cout << "false\n";

    return 0;
}