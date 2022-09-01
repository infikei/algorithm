#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        m[str]++;
    }
    for (int i = 1; i < N; i++) {
        cin >> str;
        m[str]++;
    }

    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if ((iter->second) % 2 == 1) {
            cout << iter->first << '\n';
            break;
        }
    }

    return 0;
}