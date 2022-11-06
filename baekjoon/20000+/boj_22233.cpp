#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int N, M;
unordered_set<string> keyword_set;

vector<string> split(const string a) {
    vector<string> result;
    int a_size = a.length();
    string tmp = "";

    for (int i = 0; i < a_size; i++) {
        if (a[i] == ',') {
            result.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += a[i];
        }
    }
    result.push_back(tmp);

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;

    string input;

    for (int n = 0; n < N; n++) {
        cin >> input;
        keyword_set.insert(input);
    }

    for (int m = 0; m < M; m++) {
        cin >> input;

        vector<string> vec = split(input);
        int vec_size = vec.size();

        for (int i = 0; i < vec_size; i++) {
            string keyword = vec[i];
            if (keyword_set.find(keyword) != keyword_set.end()) {
                keyword_set.erase(keyword_set.find(keyword));
            }
        }

        int keyword_set_size = keyword_set.size();
        cout << keyword_set_size << '\n';
    }

    return 0;
}