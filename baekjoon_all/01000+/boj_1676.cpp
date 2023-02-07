// Solve 2022-06-08
// Update 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;
    cout << n / 5 + n / 25 + n / 125 << '\n';

    // 5의 배수가 곱해지는 경우에는 항상 0이 생긴다.
    // 특히, 5의 a제곱의 배수가 곱해지는 경우에는 항상 0이 a개 생긴다.
    // 이유를 간략히 설명하면,
    // c * 5^a가 곱해질 때에는 이미 이전에 c * 2^a가 곱해진 상태이므로 이 두 수가 만나서 10^a가 만들어지기 때문이다.

    // 이 점을 이용하면, 문제에서 주어진 500 이하의 수 중에서 5의 거듭제곱은 5, 25, 125 밖에 없으므로,
    // n 이하의 수 중 5의 배수의 개수 + 25의 배수의 개수 + 125의 배수의 개수를 구하면 된다.

    return 0;
}