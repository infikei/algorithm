// Solve 2023-06-23

// 이 문제는 현재 맞힌 사람(n)에 따라 풀이가 달라집니다.
// 아래 코드는 이 문제에 대한 풀이가 아니며,
// n의 값, 즉 맞힌 사람이 달라짐에 따라 제출해야 하는 풀이의 문제 번호를 구하는 코드입니다.

// 참고로, 맞힌 사람이 198045명이 되면, 18825번 문제(지금 문제)를 푸는 소스 코드를 제출해야 하는 모순적인 상황이 찾아오게 된다.. 근데 그런 날이 과연 찾아올까..?

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cout << "현재 맞힌 사람의 수를 입력하세요 : ";
    cin >> n;
    cout << "n = " << n << '\n';

    n += 2;
    cout << "n + 2 = " << n << '\n';

    int p = n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            p = i;
            break;
        }
    }
    cout << "p = (n + 2를 나누는 가장 작은 소수) = " << p << '\n';

    vector<bool> vec(p + 1);
    vector<int> primes;
    for (int i = 2; i <= p; i++) {
        if (vec[i]) continue;

        primes.push_back(i);

        for (int j = i + i; j <= p; j += i) {
            vec[j] = true;
        }
    }
    cout << "k = (p 이하의 소수의 개수) = " << SIZE(primes) << '\n';
    cout << "따라서 " << 999 + SIZE(primes) << "번 문제를 푸는 소스 코드를 제출해야 한다." << '\n';

    return 0;
}
