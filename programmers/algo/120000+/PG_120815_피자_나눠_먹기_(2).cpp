// Solve 2023-03-20

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int n2 = n;
    while (n2 % 6 != 0) {
        n2 += n;
    }
    answer = n2 / 6;

    return answer;
}
