#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string bin_num, oct_num;
    cin >> bin_num;

    int k = (int)(bin_num.length()) % 3;
    if (k == 2) {
        int j = (bin_num[0] - '0') * 2;
        j += bin_num[1] - '0';
        oct_num = ('0' + j);
    }
    else if (k == 1) {
        oct_num = bin_num[0];
    }
    for (int i = k; i < bin_num.length(); i += 3) {
        int j = (bin_num[i] - '0') * 4;
        j += (bin_num[i + 1] - '0') * 2;
        j += bin_num[i + 2] - '0';
        oct_num += ('0' + j);
    }

    cout << oct_num << '\n';

    return 0;
}