// Solve 2023-08-14

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    if (n % 2 == 0) {
        answer = n * (n / 2 + 1) * (n + 1) / 3;
    }
    else {
        answer = (n + 1) * (n + 1) / 4;
    }

    return answer;
}
