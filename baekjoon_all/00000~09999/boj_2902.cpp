#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string long_name;
    cin >> long_name;

    string short_name;
    short_name.push_back(long_name[0]);
    for (int i = 1; i < (int)long_name.length(); i++) {
        if (long_name[i] == '-') {
            short_name.push_back(long_name[i + 1]);
        }
    }

    cout << short_name << '\n';

    return 0;
}