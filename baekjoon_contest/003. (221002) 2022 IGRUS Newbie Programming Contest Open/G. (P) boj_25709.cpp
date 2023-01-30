#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int cnt = 0;

    string strN;
    cin >> strN;

    while (strN.find('1') != string::npos) {
        int idx = strN.find('1');
        strN = strN.substr(0, idx) + strN.substr(idx + 1, (int)strN.length() - 1 - idx);
        cnt++;
    }

    int N = 0;
    if (strN != "") {
        N = stoi(strN);
    }

    while (N > 0) {
        if (N % 10 == 1) {
            N = N / 10;
        }
        else {
            N--;
        }
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}