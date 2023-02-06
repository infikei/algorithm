#include <iostream>
using namespace std;

long long road_length[999999];
long long oil_price[100000];
long long N, answer, oil_price_min;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> road_length[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> oil_price[i];
    }

    answer = 0;
    oil_price_min = oil_price[0];
    for (int i = 0; i < N - 1; i++) {
        oil_price_min = min(oil_price_min, oil_price[i]);
        answer += road_length[i] * oil_price_min;
    }

    cout << answer << '\n';

    return 0;
}