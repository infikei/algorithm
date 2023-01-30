#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    int k;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int tmp;
            cin >> tmp;

            if (tmp == 1) {
                v.push_back((row + col) % 2);
            }
            else if (tmp == 2) {
                k = (row + col) % 2;
            }
        }
    }

    int v_sz = v.size();
    bool b = true;
    for (int i = 0; i < v_sz; i++) {
        if (v[i] == k) {
            b = false;
            break;
        }
    }

    if (b) {
        cout << "Lena" << '\n';
    }
    else {
        cout << "Kiriya" << '\n';
    }

    return 0;
}