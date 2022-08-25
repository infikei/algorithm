#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C, Rg, Cg, Rp, Cp;
vector<string> room;

void input() {
    cin >> R >> C;
    cin >> Rg >> Cg >> Rp >> Cp;
    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        room.push_back(tmp);
    }
}

int solve() {
    int Rp_begin = 0, Cp_begin = 0;
    for (int i = 0; i < R; i++) {
        if (room[i].find('P') != string::npos) {
            Rp_begin = i;
            for (int j = 0; j < C; j++) {
                if (room[i][j] == 'P') {
                    Cp_begin = j;
                    break;
                }
            }
            break;
        }
    }

    int Rp_end = Rp_begin + Rp;
    int Cp_end = Cp_begin + Cp;
    for (int i = Rp_begin; i < Rp_end; i++) {
        if (i >= R) {
            return 0;
        }
        for (int j = Cp_begin; j < Cp_end; j++) {
            if (j >= C) {
                return 0;
            }

            if (room[i][j] != 'P') {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    cout << solve() << '\n';

    return 0;
}