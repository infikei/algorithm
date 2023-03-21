// Solve 2023-03-20

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;

    sort(array.begin(), array.end());
    int n = array.size();

    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (array[j] != array[i]) {
                break;
            }
            cnt++;
        }

        if (cnt > max_cnt) {
            max_cnt = cnt;
            answer = array[i];
        }
        else if (cnt == max_cnt) {
            answer = -1;
        }
    }
    
    return answer;
}
