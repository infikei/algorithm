#include <iostream>
#include <string>
using namespace std;

bool check_error;
string ans;
string HG[26] = {"aespa", "baekjoon", "cau", "debug", "edge", "firefox", "golang", "haegang", "iu", "java", "kotlin", "lol", "mips", "null", "os", "python", "query", "roka", "solvedac", "tod", "unix", "virus", "whale", "xcode", "yahoo", "zebra"};

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string word;
    cin >> word;

    int word_sz = word.length();
    for (int i = 0; i < word_sz; ) {
        char now_ch = word[i];
        string cmp_str = HG[now_ch - 'a'];
        int cmp_str_sz = (int)cmp_str.length();
        if (i + cmp_str_sz > word_sz || word.substr(i, (int)cmp_str.length()) != cmp_str) {
            check_error = true;
            break;
        }
        ans += now_ch;
        i += cmp_str_sz;
    }

    if (check_error) {
        cout << "ERROR!" << '\n';
    }
    else {
        cout << "It's HG!" << '\n';
        cout << ans << '\n';
    }

    return 0;
}