#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;

    for (int k = 0; k < n; k++) {
        string line;
        getline(cin, line);
        if (line == "") getline(cin, line);
        int line_len = line.length();

        bool is_palindrome = true;
        for (int i = 0; i < line_len / 2; i++) {
            char ch0 = line[i];
            char ch1 = line[line_len - 1 - i];
            if (ch0 >= 'A' && ch0 <= 'Z') ch0 = ch0 - 'A' + 'a';
            if (ch1 >= 'A' && ch1 <= 'Z') ch1 = ch1 - 'A' + 'a';

            if (ch0 != ch1) {
                is_palindrome = false;
                break;
            }
        }

        if (is_palindrome) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}