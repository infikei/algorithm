#include <iostream>
#include <string>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

string s[5];
char vowel[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool isVowel(char ch) {
    for (int i = 0; i < 6; i++) {
        if (ch == vowel[i]) return true;
    }
    return false;
}

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        string new_str;
        int str_len = s[i].length();

        for (int j = 0; j < str_len - 2; j++) {
            if (isVowel(s[i][j]) && !isVowel(s[i][j + 1]) && !isVowel(s[i][j + 2])) continue;
            new_str.push_back(s[i][j]);
        }
        if (str_len > 1) new_str.push_back(s[i][str_len - 2]);
        new_str.push_back(s[i][str_len - 1]);

        reverse(new_str.begin(), new_str.end());
        s[i] = new_str;
    }

    reverse(s, s + n);

    for (int i = 0; i < n; i++) {
        cout << s[i] << ' ';
    }
    cout << '\n';

    return 0;
}