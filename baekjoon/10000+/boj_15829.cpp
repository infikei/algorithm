#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    long long size, r = 31, m = 1234567891;
    string input;
    cin >> size >> input;

    long long ans = input[size - 1] - 'a' + 1;

    for (int i = size - 2; i >= 0; i--) {
        ans *= r;
        ans = ans % m;
        ans += input[i] - 'a' + 1;
    }
    
    ans = ans % m;
    cout << ans << '\n';

    return 0;
}