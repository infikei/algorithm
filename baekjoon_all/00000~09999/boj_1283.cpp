#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check[26];

string str_lower(string a) {
    string result = "";
    int a_sz = a.length();

    for (int i = 0; i < a_sz; i++) {
        if ('A' <= a[i] && a[i] <= 'Z') {
            result += (a[i] - 'A' + 'a');
        }
        else {
            result += a[i];
        }
    }

    return result;
}

int key_idx(string menu) {
    string menu_lower = str_lower(menu);

    if (!check[menu_lower[0] - 'a']) {
        check[menu_lower[0] - 'a'] = true;
        return 0;
    }

    int i = menu_lower.find(' ');

    while (i != string::npos) {
        i++;
        if (!check[menu_lower[i] - 'a']) {
            check[menu_lower[i] - 'a'] = true;
            return i;
        }

        i = menu_lower.find(' ', i);
    }

    int menu_sz = menu.length();
    for (int i = 1; i < menu_sz; i++) {
        if (menu_lower[i] == ' ') {
            i++;
            continue;
        }

        if (!check[menu_lower[i] - 'a']) {
            check[menu_lower[i] - 'a'] = true;
            return i;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        string menu;
        getline(cin, menu);
        if (menu == "\0") {
            getline(cin, menu);
        }

        int idx = key_idx(menu);
        if (idx == -1) {
            cout << menu << '\n';
        }
        else {
            int menu_sz = menu.length();
            if (idx > 0) {
                cout << menu.substr(0, idx);
            }
            cout << '[' << menu.substr(idx, 1) << ']';
            if (idx + 1 < menu_sz) {
                cout << menu.substr(idx + 1, menu_sz - idx - 1);
            }
            cout << '\n';
        }
    }

    return 0;
}