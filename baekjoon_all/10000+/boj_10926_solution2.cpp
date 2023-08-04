// Solve 2022-06-02
// Update 2023-08-03

#include <iostream>
using namespace std;

int main() {
    char s[51];
    cin >> s;

    // ??!는 삼중 문자(삼중자, trigraph)로 사용되므로 회피 문자 \를 통해 회피한다.
    cout << s << "?\?!\n";

    return 0;
}
