#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string a_str, b_str;
    cin >> a_str >> b_str;

    reverse(a_str.begin(), a_str.end());
    reverse(b_str.begin(), b_str.end());

    int a = stoi(a_str);
    int b = stoi(b_str);

    cout << max(a, b) << '\n';

    return 0;
}