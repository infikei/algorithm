#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    cin >> N >> M;
    unordered_map<string, int> hs;
    vector<string> vt;
    string strTemp;

    for (int i = 0; i < N; i++) {
        cin >> strTemp;
        hs[strTemp]++;
    }
    for (int i = 0; i < M; i++) {
        cin >> strTemp;
        if (hs[strTemp] == 1) {
            vt.push_back(strTemp);
        }
    }

    sort(vt.begin(), vt.end());
    cout << vt.size() << '\n';
    for (int i = 0; i < vt.size(); i++) {
        cout << vt[i] << '\n';
    }

    return 0;
}