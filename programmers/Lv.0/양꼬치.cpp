// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    answer = n * 12000 + (k - n / 10) * 2000;

    return answer;
}
