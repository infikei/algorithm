// Solve 2022-08-18
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int station_dist[43] = {
        0, 91, 239, 415, 565,
        665, 750, 844, 966, 1074,
        1149, 1293, 1398, 1519, 1663,
        1825, 1908, 1964, 2008, 2046,
        2116, 2262, 2347, 2538, 2767,
        2813, 2895, 2960, 3059, 3231,
        3263, 3386, 3531, 3618, 3722,
        3816, 3941, 4032, 4124, 4218,
        4252, 4303, 4417
    };

    unordered_map<string, int> station_num = {
        { "Seoul", 0 },
        { "Yeongdeungpo", 1 },
        { "Anyang", 2 },
        { "Suwon", 3 },
        { "Osan", 4 },
        { "Seojeongri", 5 },
        { "Pyeongtaek", 6 },
        { "Seonghwan", 7 },
        { "Cheonan", 8 },
        { "Sojeongni", 9 },
        { "Jeonui", 10 },
        { "Jochiwon", 11 },
        { "Bugang", 12 },
        { "Sintanjin", 13 },
        { "Daejeon", 14 },
        { "Okcheon", 15 },
        { "Iwon", 16 },
        { "Jitan", 17 },
        { "Simcheon", 18 },
        { "Gakgye", 19 },
        { "Yeongdong", 20 },
        { "Hwanggan", 21 },
        { "Chupungnyeong", 22 },
        { "Gimcheon", 23 },
        { "Gumi", 24 },
        { "Sagok", 25 },
        { "Yangmok", 26 },
        { "Waegwan", 27 },
        { "Sindong", 28 },
        { "Daegu", 29 },
        { "Dongdaegu", 30 },
        { "Gyeongsan", 31 },
        { "Namseonghyeon", 32 },
        { "Cheongdo", 33 },
        { "Sangdong", 34 },
        { "Miryang", 35 },
        { "Samnangjin", 36 },
        { "Wondong", 37 },
        { "Mulgeum", 38 },
        { "Hwamyeong", 39 },
        { "Gupo", 40 },
        { "Sasang", 41 },
        { "Busan", 42 }
    };

    int n, q;
    cin >> n >> q;

    int time_table[86] = { 0 };
    int prev_time = 0, now_time = 0;

    for (int i = 0; i < n; i++) {
        string now_st, now_arrival, now_departure;
        cin >> now_st >> now_arrival >> now_departure;

        int now_st_num = station_num[now_st];

        if (i > 0) {
            now_time = stoi(now_arrival.substr(0, 2)) * 60 + stoi(now_arrival.substr(3, 2));

            if (now_time < prev_time) {
                now_time += 1440;
            }

            time_table[now_st_num * 2] = now_time;
            prev_time = now_time;
        }

        if (i < n - 1) {
            now_time = stoi(now_departure.substr(0, 2)) * 60 + stoi(now_departure.substr(3, 2));

            if (now_time < prev_time) {
                now_time += 1440;
            }

            time_table[now_st_num * 2 + 1] = now_time;
            prev_time = now_time;
        }
    }

    SETPRECISION(9);

    for (int i = 0; i < q; i++) {
        string query_st_1, query_st_2;
        cin >> query_st_1 >> query_st_2;

        int query_st_1_num = station_num[query_st_1];
        int query_st_2_num = station_num[query_st_2];

        double diff_dist = abs(station_dist[query_st_2_num] - station_dist[query_st_1_num]);
        double diff_time = time_table[query_st_2_num * 2] - time_table[query_st_1_num * 2 + 1];

        // 단위 보정 (station_dist에서의 1은 0.1km이므로 결과를 10으로 나누어줘야 하고, time_table의 단위는 h이 아니라 min이므로 결과에 60을 곱해줘야 한다.)

        double ans = diff_dist * 6 / diff_time;

        cout << ans << '\n';
    }

    return 0;
}
