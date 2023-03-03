// 최대공약수(GCD) 및 최소공배수(LCM) 구하는 알고리즘

#include <iostream>
using namespace std;

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

    int a = 24, b = 30;

    cout << calc_gcd(a, b) << '\n';
    cout << calc_lcm(a, b) << '\n';

    return 0;
}