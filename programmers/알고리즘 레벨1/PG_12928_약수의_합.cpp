// Solve 2023-03-21

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;

    int sqrt_of_n = sqrt(n);
    for (int i = 1; i <= sqrt_of_n; i++) {
        if (n % i == 0) {
            answer += i;
            if (i != n / i) {
                answer += n / i;
            }
            
        }
    }

    return answer;
}
