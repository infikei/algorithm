#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#define sz(v) ((int)v.size())
using namespace std;
typedef pair<int, int> pii;

string input;
stack<int> st;
vector<pii> vec_index;
bool remove_index[200] = {false};
vector<string> vec_ans;

void make_vec_index() {
    for (int i = 0; i < sz(input); i++) {
        if (input[i] == '(') {
            st.push(i);
        }
        else if (input[i] == ')') {
            vec_index.push_back(make_pair(st.top(), i));
            st.pop();
        }
    }
}

void dfs(int depth = 0) {
    if (depth == sz(vec_index)) {
        string new_input = "";
        for (int i = 0; i < sz(input); i++) {
            if (!remove_index[i]) {
                new_input += input[i];
            }
        }

        if (new_input != input) {
            vec_ans.push_back(new_input);
        }
        return;
    }

    dfs(depth + 1);

    remove_index[vec_index[depth].first] = true;
    remove_index[vec_index[depth].second] = true;
    dfs(depth + 1);
    remove_index[vec_index[depth].first] = false;
    remove_index[vec_index[depth].second] = false;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> input;

    make_vec_index(); // 괄호 쌍의 index 값들을 저장

    dfs(); // 괄호 쌍을 제거해서 나올 수 있는 식들을 저장

    sort(vec_ans.begin(), vec_ans.end()); // 정렬
    vec_ans.erase(unique(vec_ans.begin(), vec_ans.end()), vec_ans.end()); // 서로 다른 식만을 출력해야 하므로 중복 제거

    for (int i = 0; i < sz(vec_ans); i++) {
        cout << vec_ans[i] << '\n';
    }

    return 0;
}