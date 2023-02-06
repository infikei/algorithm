#include <iostream>
#include <algorithm>
using namespace std;

int RGB[1000][3];
int N;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    cin >> RGB[0][0] >> RGB[0][1] >> RGB[0][2];

    for (int i = 1; i < N; i++) {
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
        RGB[i][0] += min(RGB[i - 1][1], RGB[i - 1][2]);
        RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
        RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]);
    }

    cout << min(RGB[N - 1][0], min(RGB[N - 1][1], RGB[N - 1][2])) << '\n';

    return 0;
}