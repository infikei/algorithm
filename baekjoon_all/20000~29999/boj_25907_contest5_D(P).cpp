#include <iostream>
using namespace std;

int N, ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    int low = 1, high = N, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        cout << "? " << mid;
        cout << endl;
        int x;
        cin >> x;

        if (x > mid - x) {
            low = mid + 1;
        }
        else if (x < mid - x) {
            high = mid;
        }
        else {
            ans = mid;
            break;
        }
    }

    cout << "! " << ans;
    cout << endl;

    return 0;
}