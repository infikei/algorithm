#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M, temp;
    cin >> N;
    vector<int> vt(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> vt[i];
    }
    sort(vt.begin(), vt.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (binary_search(vt.begin(), vt.end(), temp)) {
            cout << 1;
        }
        else {
            cout << 0;
        }
        cout << ' ';
    }
    cout << '\n';

    return 0;
}