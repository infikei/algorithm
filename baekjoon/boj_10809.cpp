#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    int ans[26];
    fill_n(ans, 26, -1);


    for (int i = 0; i < input.size(); i++) {
        if (ans[input[i] - 'a'] == -1)
            ans[input[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}