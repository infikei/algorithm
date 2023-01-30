#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, b_cnt, s_cnt;
string input;

int main() {
    fastio;

    cin >> N >> input;

    int input_len = input.length();
    int i = 0;
    while (i < input_len) {
        if (input[i] == 'b') {
            b_cnt++;
            i += 7;
        }
        else {
            s_cnt++;
            i += 8;
        }
    }

    if (b_cnt > s_cnt) {
        cout << "bigdata?\n";
    }
    else if (b_cnt < s_cnt) {
        cout << "security!\n";
    }
    else {
        cout << "bigdata? security!\n";
    }

    return 0;
}