// Solve 2023-03-19

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            answer += 2;
            if (i * i == n) {
                answer--;
            }
        }
    }

    return answer;
}
