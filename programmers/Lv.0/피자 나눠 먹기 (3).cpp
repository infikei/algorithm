// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;

    answer = (n - 1) / slice + 1;

    return answer;
}
