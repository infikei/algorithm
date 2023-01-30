#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    string s0, s1;
    cin >> s0 >> s1;
    int s_sz = s0.length();

    bool check = true;

    if (N % 2 == 0) {
        for (int i = 0; i < s_sz; i++) {
            if (s0[i] != s1[i]) {
                check = false;
                break;
            }
        }
    }
    else {
        for (int i = 0; i < s_sz; i++) {
            if (s0[i] == s1[i]) {
                check = false;
                break;
            }
        }
    }

    if (check) {
        cout << "Deletion succeeded\n";
    }
    else {
        cout << "Deletion failed\n";
    }

    return 0;
}