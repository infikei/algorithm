#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int t;
    cin >> t;

    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;

        int arr[100];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}