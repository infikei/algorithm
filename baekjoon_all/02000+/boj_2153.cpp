#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string input;
int N;

bool isPrime(int a) {
    if (a == 1) {
        return true;
    }

    double sqrt_a = sqrt(a);

    for (int i = 2; i <= sqrt_a; i++) {
        if (a % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> input;
    int input_size = input.length();

    N = 0;
    for (int i = 0; i < input_size; i++) {
        char now = input[i];
        if (now <= 'Z') {
            N += now - 'A' + 27;
        }
        else {
            N += now - 'a' + 1;
        }
    }

    if (isPrime(N)) {
        cout << "It is a prime word.";
    }
    else {
        cout << "It is not a prime word.";
    }
    cout << '\n';

    return 0;
}