#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string dogam[100001];
unordered_map<string, int> hs;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    string input;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> input;
        dogam[i] = input;
        hs[input] = i;
    }

    for (int i = 1; i <= M; i++) {
        cin >> input;
        if (hs.find(input) != hs.end()) {
            cout << hs.find(input)->second << '\n';
        }
        else {
            cout << dogam[stoi(input)] << '\n';
        }
    }

    return 0;
}