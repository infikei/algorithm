#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int i = 0;
    while (true) {
        i++;
        int a, b;
        string s;
        cin >> a >> s >> b;

        if (s == "E") {
            break;
        }
        
        bool ans;
        if (s == ">") {
            ans = (a > b);
        }
        else if (s == ">=") {
            ans = (a >= b);
        }
        else if (s == "<") {
            ans = (a < b);
        }
        else if (s == "<=") {
            ans = (a <= b);
        }
        else if (s == "==") {
            ans = (a == b);
        }
        else if (s == "!=") {
            ans = (a != b);
        }

        cout << "Case " << i << ": ";
        if (ans) {
            cout << "true\n";
        }
        else {
            cout << "false\n";
        }
    }

    return 0;
}