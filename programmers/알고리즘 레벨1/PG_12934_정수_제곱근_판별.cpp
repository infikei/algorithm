// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long x = 0;
    long long answer = -1;

    while (true) {
        x++;
        long long x2 = x * x;
        if (x2 == n) {
            answer = x2 + 2 * x + 1;
            break;
        }
        else if (x2 > n) {
            break;
        }
    }

    return answer;
}
