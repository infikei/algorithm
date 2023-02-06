#include <iostream>
using namespace std;
typedef long long ll;

ll N, K;
bool first_check, ans;
int arr_y[100001];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr_y[i];
    }

    cin >> K;

    if (arr_y[1] < K) {
        first_check = true;
    }

    for (ll i = 1; i <= N; i++) {
        if ((ll)arr_y[i] == K * i) {
            ans = true;
            break;
        }
        bool now_check = ((ll)arr_y[i] < K * i);
        if (first_check != now_check) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "T\n";
    }
    else {
        cout << "F\n";
    }

    return 0;
}