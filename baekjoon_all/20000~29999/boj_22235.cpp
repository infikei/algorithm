#include <iostream>
#include <string>
using namespace std;

int N, now_time, now_station;
string now_time_str;
bool check = false;

int time_str_to_int(const string &a) {
    int h = stoi(a.substr(0, 2));
    int m = stoi(a.substr(3, 2));
    int s = 0;
    if (a.length() == 8) {
        s = stoi(a.substr(6, 2));
    }

    return h * 3600 + m * 60 + s;
}

string time_int_to_str(const int &a) {
    int h = a / 3600;
    int m = (a / 60) % 60;
    int s = a % 60;

    string result = "";
    if (h < 10) {
        result += '0';
    }
    result += to_string(h) + ':';
    if (m < 10) {
        result += '0';
    }
    result += to_string(m) + ':';
    if (s < 10) {
        result += '0';
    }
    result += to_string(s);

    return result;
}

int time_taken(const int &a_begin, const int &a_end) {
    int result = (a_end - a_begin) * 140 - 20;

    if (a_begin <= 210 && a_end >= 211) {
        result += 60;
    }
    if (a_begin <= 220 && a_end >= 221) {
        result += 120;
    }
    if (a_begin <= 221 && a_end >= 222) {
        result += 120;
    }
    if (a_begin <= 222 && a_end >= 223) {
        result += 60;
    }
    if (a_begin <= 225 && a_end >= 226) {
        result += 60;
    }
    if (a_begin <= 238 && a_end >= 239) {
        result += 60;
    }
    if (a_begin <= 245 && a_end >= 246) {
        result += 120;
    }
    if (a_begin <= 247 && a_end >= 248) {
        result += 180;
    }
    if (a_begin <= 249 && a_end >= 250) {
        result += 120;
    }
    if (a_begin <= 250 && a_end >= 251) {
        result += 60;
    }
    if (a_begin <= 256 && a_end >= 257) {
        result += 60;
    }
    if (a_begin <= 266 && a_end >= 267) {
        result += 60;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> now_time_str >> N;
    now_time = time_str_to_int(now_time_str);
    now_station = 225;

    for (int n = 0; n < N; n++) {
        string train_departure_station_str, train_arrive_station_str, train_departure_time_str;
        cin >> train_departure_station_str >> train_arrive_station_str >> train_departure_time_str;
        int train_departure_station = stoi(train_departure_station_str.substr(1, 3));
        int train_arrive_station = stoi(train_arrive_station_str.substr(1, 3));
        int train_departure_time = time_str_to_int(train_departure_time_str);

        if (now_station < train_departure_station) {
            continue;
        }
        if (now_station >= train_arrive_station) {
            continue;
        }

        int train_time = train_departure_time + time_taken(train_departure_station, now_station) + 20;
        if (now_time > train_time) {
            continue;
        }

        train_time += time_taken(now_station, train_arrive_station);
        now_station = train_arrive_station;
        now_time = train_time;

        if (now_time >= 24 * 3600) {
            break;
        }

        if (now_station == 272) {
            check = true;
            break;
        }
    }

    if (check) {
        cout << time_int_to_str(now_time) << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}