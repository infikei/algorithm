#include <iostream>
#include <string>
#include <map>
using namespace std;

string str;
map<string, int> m;
int sum = 0;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    while (getline(cin, str)) {
        sum++;
        m[str]++;
    }

    cout << fixed;
    cout.precision(4);

    map<string, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << ' ';
        double d = iter->second * 100;
        cout << d / sum << '\n';
    }

    return 0;
}