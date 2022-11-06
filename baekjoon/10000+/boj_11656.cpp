#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string input;
    cin >> input;
    int input_size = input.length();

    vector<string> vec;
    for (int i = 0; i < input_size; i++) {
        vec.push_back(input.substr(i, input_size - i));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < input_size; i++) {
        cout << vec[i] << '\n';
    }

    return 0;
}