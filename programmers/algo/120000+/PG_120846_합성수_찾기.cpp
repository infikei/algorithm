// Solve 2023-03-26

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> sieve(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            for (int j = i + i; j <= n; j += i) {
                sieve[j] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            answer++;
        }
    }

    return answer;
}
