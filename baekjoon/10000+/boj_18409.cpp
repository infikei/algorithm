#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

char aeiou[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    fastio;

    int N;
    string S;
    cin >> N >> S;

    int cnt = 0;

    for (auto s : S) {
        for (auto a : aeiou) {
            if (s == a) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}