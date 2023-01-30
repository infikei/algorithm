#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << "0\n";
            continue;
        }
        else if (n == 1) {
            string name, type;
            cin >> name >> type;
            cout << "1\n";
            continue;
        }

        string clothes_type[31];
        int clothes_num[31];

        string name, type;
        cin >> name >> type;
        clothes_type[0] = type;
        clothes_num[0] = 1;
        int clothes_size = 1;

        for (int i = 1; i < n; i++) {
            cin >> name >> type;
            string *p = find(clothes_type, clothes_type + clothes_size, type);
            if (p != clothes_type + clothes_size) {
                clothes_num[p - clothes_type]++;
            }
            else {
                clothes_type[clothes_size] = type;
                clothes_num[clothes_size] = 1;
                clothes_size++;
            }
        }

        int ans = 1;
        for (int i = 0; i < clothes_size; i++) {
            ans *= clothes_num[i] + 1;
        }
        ans--;
        cout << ans << '\n';
    }

    return 0;
}