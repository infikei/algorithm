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

    for (int n = 0; n < N; n++) {
        cin >> str;
        m[str]++;
    }

    map<string, int>::iterator iter;
    string max_str = "";
    int max_int = 0;

    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > max_int) {
            max_str = iter->first;
            max_int = iter->second;
        }
        else if (iter->second == max_int) {
            if (iter->first < max_str) {
                max_str = iter->first;
            }
        }
    }

    cout << max_str << '\n';

    return 0;
}