#include <iostream>
#include <string>
using namespace std;

int DP[11];
int N, K;

void dp_calc() {
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i < 11; i++) {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }
}

string solve(int n, int k) {
    if (k >= DP[n]) {
        return "-1";
    }

    if (n <= 3) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            if (k == 0) {
                return "1+1";
            }
            return "2";
        }
        if (k == 0) {
            return "1+1+1";
        }
        if (k == 1) {
            return "1+2";
        }
        if (k == 2) {
            return "2+1";
        }
        return "3";
    }

    if (k < DP[n - 1]) {
        return "1+" + solve(n - 1, k);
    }
    else if (k < DP[n - 1] + DP[n - 2]) {
        return "2+" + solve(n - 2, k - DP[n - 1]);
    }
    else {
        return "3+" + solve(n - 3, k - DP[n - 1] - DP[n - 2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    dp_calc();

    cin >> N >> K;

    cout << solve(N, K - 1) << '\n';

    return 0;
}