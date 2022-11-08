#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, cnt[26];

int main() {
    fastio;

    cin >> N;

    for (int n = 0; n < N; n++) {
        string first_name;
        cin >> first_name;
        cnt[first_name[0] - 'a']++;
    }

    bool check = false;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            check = true;
            cout << (char)('a' + i);
        }
    }
    if (!check) {
        cout << "PREDAJA";
    }
    cout << '\n';

    return 0;
}