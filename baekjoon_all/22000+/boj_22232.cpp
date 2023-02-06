#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef pair<string, string> pss;

int N, M;
string input_str;
vector<pss> file_vec;
unordered_map<string, int> hs;

bool cmp(const pss &a, const pss &b) {
    if (a.first == b.first) {
        bool a_bool = (hs.find(a.second) != hs.end());
        bool b_bool = (hs.find(b.second) != hs.end());
        if (a_bool == b_bool) {
            return a.second < b.second;
        }
        else if (a_bool) {
            return true;
        }
        else {
            return false;
        }
    }
    return a.first < b.first;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input_str;
        int cur = input_str.find('.');
        int input_str_size = input_str.length();
        file_vec.push_back(make_pair(input_str.substr(0, cur), input_str.substr(cur + 1, input_str_size - cur + 1)));
    }
    for (int i = 0; i < M; i++) {
        cin >> input_str;
        hs[input_str] = 1;
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        cout << file_vec[i].first << '.' << file_vec[i].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    sort(file_vec.begin(), file_vec.end(), cmp);

    print();

    return 0;
}