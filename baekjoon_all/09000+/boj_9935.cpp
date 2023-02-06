#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string input_str, bomb, output_str;
    cin >> input_str >> bomb;

    int bomb_size = bomb.length(), output_str_size = 0;
    char bomb_end = bomb[bomb_size - 1];

    for (auto ch : input_str) {
        output_str.push_back(ch);
        output_str_size++;

        if (output_str_size < bomb_size) {
            continue;
        }

        if (ch == bomb_end && output_str.substr(output_str_size - bomb_size, bomb_size) == bomb) {
            for (int i = 0; i < bomb_size; i++) {
                output_str.pop_back();
            }
            output_str_size -= bomb_size;
        }
    }

    if (output_str == "") {
        output_str = "FRULA";
    }
    cout << output_str << '\n';

    return 0;
}