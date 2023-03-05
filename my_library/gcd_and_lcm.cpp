// 유클리드 호제법을 이용하여 최대공약수(GCD)와 최소공배수(LCM)를 구한다.

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int calc_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return calc_gcd(b, a % b);
}

int calc_lcm(int a, int b) {
    return a / calc_gcd(a, b) * b;
}

int main() {
    FASTIO;

    cout << "수를 입력하세요 : ";
    int a;
    cin >> a;

    cout << "수를 하나 더 입력하세요 : ";
    int b;
    cin >> b;

    cout << a << "와 " << b << "의 최대공약수는 " << calc_gcd(a, b) << "이다.\n";
    cout << a << "와 " << b << "의 최소공배수는 " << calc_lcm(a, b) << "이다.\n";

    return 0;
}