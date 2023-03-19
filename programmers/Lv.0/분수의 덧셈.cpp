// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

int calc_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return calc_gcd(b, a % b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);

    answer[0] = numer1 * denom2 + numer2 * denom1;
    answer[1] = denom1 * denom2;

    int gcd = calc_gcd(answer[0], answer[1]);
    for (int i = 0; i < 2; i++) {
        answer[i] /= gcd;
    }

    return answer;
}
