#include <iostream>
using namespace std;

int A, B, C, D;
bool arr[1001]; // 소수이면 false, 아니면 true

int cnt(int a, int b) {
    int res = 0;
    for (int i = a; i <= b; i++) {
        if (!arr[i]) {
            res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    for (int i = 2; i <= 1000; i++) {
        if (arr[i]) {
            continue;
        }
        for (int j = 2 * i; j <= 1000; j += i) {
            arr[j] = true;
        }
    }

    cin >> A >> B >> C >> D;

    int cnt0 = cnt(A, B);
    int cnt1 = cnt(C, D);

    if (A <= D && C <= B) {
        cnt0 += (cnt(max(A, C), min(B, D)) % 2);
    }

    if (cnt0 > cnt1) {
        cout << "yt\n";
    }
    else {
        cout << "yj\n";
    }

    return 0;
}