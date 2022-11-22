#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int n, val;
    char op;
    cin >> val;

    while (true) {
        cin >> op;
        if (op == '=') {
            break;
        }
        cin >> n;
        if (op == '+') {
            val += n;
        }
        else if (op == '-') {
            val -= n;
        }
        else if (op == '*') {
            val *= n;
        }
        else {
            val /= n;
        }
    }

    cout << val << '\n';

    return 0;
}