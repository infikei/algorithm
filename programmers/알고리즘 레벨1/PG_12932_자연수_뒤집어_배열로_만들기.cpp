// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    while (n > 0) {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}
