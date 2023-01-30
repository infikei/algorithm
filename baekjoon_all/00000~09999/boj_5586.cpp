#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string S;
    cin >> S;

    int cntJOI = 0, cntIOI = 0;

    int i = S.find("JOI");
    while (i != string::npos) {
        cntJOI++;
        i = S.find("JOI", i + 1);
    }

    i = S.find("IOI");
    while (i != string::npos) {
        cntIOI++;
        i = S.find("IOI", i + 1);
    }

    cout << cntJOI << '\n';
    cout << cntIOI << '\n';

    return 0;
}