// Solve 2023-03-27

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            answer.push_back(i);
            n /= i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    return answer;
}
