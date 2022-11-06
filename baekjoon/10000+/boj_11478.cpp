#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string S, strTemp;
    cin >> S;
    int SIZE = S.size();

    unordered_map<string, int> hs;
    for (int begin = 0; begin < SIZE; begin++) {
        for (int end = begin; end < SIZE; end++) {
            strTemp = S.substr(begin, end - begin + 1);
            hs[strTemp]++;
        }
    }

    cout << hs.size() << '\n';

    return 0;
}