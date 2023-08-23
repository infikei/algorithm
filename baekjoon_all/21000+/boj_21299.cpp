// Solve 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    getline(cin, s);

    if (s == "Marathon Edition 우승자") {
        cout << "장려상\n";
        cout << "레고 타워 브리지 - 10214\n";
        cout << "sait2000\n";
    }
    else if (s == "Marathon Edition 준우승자 및 ReguIar Edition 준우승자") {
        cout << "장려상\n";
        cout << "Katamari Damacy REROLL\n";
        cout << "cubelover\n";
    }
    else if (s == "ReguIar Edition 우승자 및 Speedrun Edition 우승자") {
        cout << "장려상\n";
        cout << "(도서) Speedrun Science: A Long Guide To Short Playthroughs\n";
        cout << "xiaowuc1\n";
    }
    else if (s == "Speedrun Edition 준우승자") {
        cout << "장려상\n";
        cout << "치킨 기프티콘\n";
        cout << "rubix\n";
    }
    else if (s == "이 대회에 참가하지 않은 사람 중 2019년 대회 최고 등수") {
        cout << "결근상\n";
        cout << "치킨 기프티콘\n";
        cout << "hyeonguk\n";
    }
    else if (s == "모든 에디션에서 총점이 160억점에 가장 가까운 사람") {
        cout << "대상\n";
        cout << "16GB USB\n";
        cout << "2u_my_light\n";
    }
    else if (s == "홀수와 짝수의 대결 문제의 오류를 발견한 사람") {
        cout << "QA 상\n";
        cout << "치킨 기프티콘\n";
        cout << "namnamseo\n";
    }
    else if (s == "4차 산업 혁명을 기계학습 없이 서브태스크 2까지만 푼 사람 중 추첨") {
        cout << "UPWF 위원회 특별상\n";
        cout << "(도서) 4차 산업혁명은 없다\n";
        cout << "pichulia\n";
    }
    else if (s == "배중률교를 정해가 아닌 방법으로 푼 사람 중 추첨") {
        cout << "직관주의자상\n";
        cout << "치킨 기프티콘\n";
        cout << "dotorya\n";
    }
    else if (s == "Marathon Edition에서 Nonogram QR을 마지막으로 1점 이상 획득한 사람") {
        cout << "QR 분해 상\n";
        cout << "바코드 스캐너\n";
        cout << "201812106\n";
    }
    else if (s == "연속합 2147483647 첫 0점자") {
        cout << "Re: 제로부터 시작하는 다이나믹 프로그래밍 상\n";
        cout << "빵\n";
        cout << "zigui\n";
    }
    else if (s == "Beginning the Hunt 첫 만점자") {
        cout << "\"Ghudegy Cup looks too intense for me\" 상\n";
        cout << "Roller Coaster Tycoon 2: Triple Thrill Pack\n";
        cout << "portableangel\n";
    }
    else if (s == "대회에 참여하였고 A+B (MC)에 제출하지 않은 사람 중 추첨") {
        cout << "You Need a Minecraft 상\n";
        cout << "Minecraft\n";
        cout << "greimul\n";
    }

    return 0;
}
