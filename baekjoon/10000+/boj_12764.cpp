#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

struct cmp {
    bool operator()(pii a, pii b) {
        if (a.second == b.second) {
            return a.first > b.first; // 종료 시각이 같으면 자리 번호로 정렬
        }
        return a.second > b.second; // 종료 시각으로 정렬
    }
};

int N;
vector<pii> times;
int seats;
vector<int> users;
priority_queue<pii, vector<pii>, cmp> using_seats;
priority_queue<int, vector<int>, greater<int> > empty_seats;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    int P, Q;
    for (int i = 0; i < N; i++) {
        cin >> P >> Q;
        times.push_back(make_pair(P, Q));
    }

    sort(times.begin(), times.end());
    int times_size = times.size();
    seats = 0;

    for (int i = 0; i < times_size; i++) {
        int now_time = times[i].first;

        while (!using_seats.empty() && using_seats.top().second < now_time) {
            int empty_seat = using_seats.top().first;
            using_seats.pop();

            empty_seats.push(empty_seat);
        }

        if (!empty_seats.empty()) {
            int empty_seat = empty_seats.top();
            empty_seats.pop();

            using_seats.push(make_pair(empty_seat, times[i].second));
            users[empty_seat]++;
        }
        else {
            using_seats.push(make_pair(seats, times[i].second));
            seats++;
            users.push_back(1);
        }
    }

    cout << seats << '\n';

    for (int i = 0; i < seats; i++) {
        cout << users[i] << ' ';
    }
    cout << '\n';

    return 0;
}