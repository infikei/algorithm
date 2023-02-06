// Solve 2022-06-02
// Update 2023-02-07

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    // ??!는 삼중 문자(삼중자, trigraph)로 사용되므로 회피 문자 \를 통해 회피한다.
    cout << s << "?\?!\n";

    return 0;
}