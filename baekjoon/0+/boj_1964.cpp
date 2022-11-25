#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    // ans = 1 + N*(N+1)/2*3 + N 으로 계산할 수 있다.
    // 연산 횟수를 줄이기 위해 아래의 식으로 단순화하였고,
    // 또한 중간중간 나머지 연산을 해주면서도 답이 정확하게 나올 수 있도록 식을 적당하게 쪼개주어야 한다.
    // ans = 3*N*N/2 + 5*N/2 + 1
    // ans = (3*N+5) * N/2 + 1
    N = N % 45678;
    int ans = (3 * N + 5) % 45678;
    ans = (ans * N / 2 + 1) % 45678;
    cout << ans << '\n';

    return 0;
}