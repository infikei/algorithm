// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;

    if (price >= 500000) {
        answer = price * 4 / 5;
    }
    else if (price >= 300000) {
        answer = price * 9 / 10;
    }
    else if (price >= 100000) {
        answer = price * 19 / 20;
    }
    else {
        answer = price;
    }

    return answer;
}
