#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string input, input2, input3;
int N, Q;
double ans;
int time_arr[86];
int dist_arr[43] = {0, 91, 239, 415, 565, 665, 750, 844, 966, 1074, 1149, 1293, 1398, 1519, 1663, 1825, 1908, 1964, 2008, 2046, 2116, 2262, 2347, 2538, 2767, 2813, 2895, 2960, 3059, 3231, 3263, 3386, 3531, 3618, 3722, 3816, 3941, 4032, 4124, 4218, 4252, 4303, 4417};
unordered_map<string, int> hs;

void initialize_hs() {
    hs["Seoul"] = 0;
    hs["Yeongdeungpo"] = 1;
    hs["Anyang"] = 2;
    hs["Suwon"] = 3;
    hs["Osan"] = 4;
    hs["Seojeongri"] = 5;
    hs["Pyeongtaek"] = 6;
    hs["Seonghwan"] = 7;
    hs["Cheonan"] = 8;
    hs["Sojeongni"] = 9;
    hs["Jeonui"] = 10;
    hs["Jochiwon"] = 11;
    hs["Bugang"] = 12;
    hs["Sintanjin"] = 13;
    hs["Daejeon"] = 14;
    hs["Okcheon"] = 15;
    hs["Iwon"] = 16;
    hs["Jitan"] = 17;
    hs["Simcheon"] = 18;
    hs["Gakgye"] = 19;
    hs["Yeongdong"] = 20;
    hs["Hwanggan"] = 21;
    hs["Chupungnyeong"] = 22;
    hs["Gimcheon"] = 23;
    hs["Gumi"] = 24;
    hs["Sagok"] = 25;
    hs["Yangmok"] = 26;
    hs["Waegwan"] = 27;
    hs["Sindong"] = 28;
    hs["Daegu"] = 29;
    hs["Dongdaegu"] = 30;
    hs["Gyeongsan"] = 31;
    hs["Namseonghyeon"] = 32;
    hs["Cheongdo"] = 33;
    hs["Sangdong"] = 34;
    hs["Miryang"] = 35;
    hs["Samnangjin"] = 36;
    hs["Wondong"] = 37;
    hs["Mulgeum"] = 38;
    hs["Hwamyeong"] = 39;
    hs["Gupo"] = 40;
    hs["Sasang"] = 41;
    hs["Busan"] = 42;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    initialize_hs();

    cin >> N >> Q;

    int previous_time = 0, now_time = 0;

    for (int i = 0; i < N; i++) {
        cin >> input >> input2 >> input3;
        int now_st = hs.find(input)->second;

        if (i > 0) {
            now_time = stoi(input2.substr(0, 2)) * 60;
            now_time += stoi(input2.substr(3, 2));

            if (now_time < previous_time) {
                now_time += 24 * 60;
            }

            time_arr[now_st * 2] = now_time;
            previous_time = now_time;
        }
        if (i < N - 1) {
            now_time = stoi(input3.substr(0, 2)) * 60;
            now_time += stoi(input3.substr(3, 2));

            if (now_time < previous_time) {
                now_time += 24 * 60;
            }

            time_arr[now_st * 2 + 1] = now_time;
            previous_time = now_time;
        }
    }

    cout << fixed;
    cout.precision(9);

    for (int i = 0; i < Q; i++) {
        cin >> input >> input2;
        int start_st = hs.find(input)->second;
        int arrive_st = hs.find(input2)->second;

        ans = dist_arr[arrive_st] - dist_arr[start_st];
        // 방향이 반대일 경우 거리의 차에서 음수가 나올 수 있으므로 이때 -1을 곱한다.
        if (ans < 0) {
            ans = -ans;
        }
        ans = ans / (time_arr[arrive_st * 2] - time_arr[start_st * 2 + 1]);
        // 단위 보정 : dist_arr에서의 1은 0.1km이므로 결과를 10으로 나누어줘야 하고, time_arr의 단위는 h이 아니라 min이므로 결과에 60을 곱해줘야 한다.
        ans = ans * 6;

        cout << ans << '\n';
    }

    return 0;
}