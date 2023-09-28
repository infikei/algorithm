// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string big_num[10] = {
        "0000\n0  0\n0  0\n0  0\n0000\n",
        "   1\n   1\n   1\n   1\n   1\n",
        "2222\n   2\n2222\n2\n2222\n",
        "3333\n   3\n3333\n   3\n3333\n",
        "4  4\n4  4\n4444\n   4\n   4\n",
        "5555\n5\n5555\n   5\n5555\n",
        "6666\n6\n6666\n6  6\n6666\n",
        "7777\n   7\n   7\n   7\n   7\n",
        "8888\n8  8\n8888\n8  8\n8888\n",
        "9999\n9  9\n9999\n   9\n   9\n"
    };

    string num;
    cin >> num;

    bool flag = false;

    for (char &c : num) {
        if (flag) cout << '\n';
        else flag = true;

        cout << big_num[c - '0'];
    }

    return 0;
}
