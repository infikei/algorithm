#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 입력받은 n 값을 저장한다.
    int n, gcd_value, temp = 0;
    cin >> n;

    // 입력받은 n개 수의 최대공약수를 계산한다.
    cin >> gcd_value;
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        gcd_value = gcd(gcd_value, temp);
    }

    // 최대공약수의 약수를 출력한다.

    // 뒤의 과정에서 필요한 배열을 선언한다.
    // 이때 최대공약수의 가능한 최댓값이 10^8이고 뒤의 과정에서 sqrt(10^8)=10^4번 반복문을 실행하므로
    // 배열의 크기는 10^4이면 충분하다는 결론을 내릴 수 있다.
    int arr[10000];
    int arr_index = 0;

    // 예를 들어 최대공약수가 625이면, sqrt(625) = 25까지는 약수를 하나하나 찾는다.
    // 동시에 약수 1개당 다른 약수 1개를 배열에 저장한다. (1 출력시 625 저장, 5 출력시 125 저장, 25 출력시 25 저장)
    for (int i = 1; i <= sqrt(gcd_value); i++) {
        if (gcd_value % i == 0) {
            cout << i << '\n';
            arr[arr_index] = gcd_value / i;
            arr_index++;
        }
    }

    // 예를 들어 최대공약수가 625이면, 앞의 과정에서 1,5,25까지 이미 출력된 상태이므로
    // 뒤의 과정에서는 배열에 저장된 값들 중 25를 제외한 625,125만 출력해야 한다.
    if (arr[arr_index - 1] == sqrt(gcd_value)) {
        arr_index--;
    }

    // 배열에 저장되어있는 값을 역순으로 출력한다.
    for (int i = arr_index; i > 0; i--) {
        arr_index--;
        cout << arr[arr_index] << '\n';
    }

    return 0;
}