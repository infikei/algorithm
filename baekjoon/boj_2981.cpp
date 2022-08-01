#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    // 들어온 값들의 차이들의 최대공약수를 구해야 함
    // (이때 비교하는 순서는 결과에 영향을 주지 않으므로 그냥 들어오는 대로 비교함)
    int temp1, temp2;
    cin >> temp1 >> temp2;
    int ans = abs(temp2 - temp1);
    for (int i = 2; i < N; i++) {
        cin >> temp2;
        ans = gcd(temp2 - temp1, ans);
    }

    // 약수 검사 시 ans / 2까지만 검사해서 시간 단축하기 (ans는 반복문 이후 따로 출력함)
    for (int m = 2; m <= ans / 2; m++) {
        if (ans % m == 0) {
            cout << m << ' ';
        }
    }
    cout << ans << '\n';

    return 0;
}