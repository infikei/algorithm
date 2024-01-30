// Solve 2023-08-01
// Update 2024-01-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n;

void print(int depth = 0, string blank = "") {
    cout << blank << "\"재귀함수가 뭔가요?\"\n";

    if (depth == n) {
        cout << blank << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    else {
        cout << blank << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        cout << blank << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        cout << blank << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        print(depth + 1, blank + "____");
    }

    cout << blank << "라고 답변하였지.\n";
}

int main() {
    FASTIO;

    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    print();

    return 0;
}
