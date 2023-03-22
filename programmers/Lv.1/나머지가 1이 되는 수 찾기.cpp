// Solve 2023-03-21

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = -1;
    int i_end = sqrt(n - 1);
    for (int i = 2; i <= i_end; i++) {
        if ((n - 1) % i == 0) {
            answer = i;
            break;
        }
    }
    if (answer == -1) {
        answer = n - 1;
    }

    return answer;
}
