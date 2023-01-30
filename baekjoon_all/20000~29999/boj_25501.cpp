#include <iostream>
#include <string>
using namespace std;

int cnt;

int recursion(const string& s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const string& s){
    cnt = 0;
    return recursion(s, 0, (int)s.length() - 1);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string input;
        cin >> input;

        cout << isPalindrome(input) << ' ';
        cout << cnt << '\n';
    }

    return 0;
}