#include <iostream>
#include <string>
using namespace std;

bool check_all;
bool check[6];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string name;
    for (int i = 1; i <= 5; i++) {
        cin >> name;
        int name_sz = name.length();

        for (int j = 0; j < name_sz - 2; j++) {
            if (name[j] == 'F' && name[j + 1] == 'B' && name[j + 2] == 'I') {
                check[i] = true;
                check_all = true;
                break;
            }
        }

        if (check[i]) {
            cout << i << ' ';
        }
    }

    if (!check_all) {
        cout << "HE GOT AWAY!";
    }
    cout << '\n';

    return 0;
}