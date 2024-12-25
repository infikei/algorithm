// Solve 2023-03-25

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int fac = 1;
    while (true) {
        answer++;
        fac *= answer;
        if (fac > n) {
            answer--;
            break;
        }
    }

    return answer;
}
