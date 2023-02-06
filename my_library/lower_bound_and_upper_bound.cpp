#include <iostream>
#include <vector>
using namespace std;

#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

// 여기서 lower_bound는 v[i] >= x를 만족하는 i의 최솟값으로 정의한다.
int lower_bound(vector<int> &v, int x) {
    const int n = v.size();
    int low = -1, high = n;
    // high의 결과가 0 이상 n 이하의 값으로 나와야 하므로 초기값을 이렇게 설정해야 한다.
    // F-T 분포이며, F-T 경계에서 T 쪽을 선택해야 하므로 high를 return한다.
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (v[mid] >= x) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return high;
}

// 여기서 upper_bound는 v[i] > x를 만족하는 i의 최솟값으로 정의한다.
int upper_bound(vector<int> &v, int x) {
    const int n = v.size();
    int low = -1, high = n;
    // high의 결과가 0 이상 n 이하의 값으로 나와야 하므로 초기값을 이렇게 설정해야 한다.
    // F-T 분포이며, F-T 경계에서 T 쪽을 선택해야 하므로 high를 return한다.
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (v[mid] > x) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return high;
}

int main() {
    vector<int> v = { 1, 2, 2, 2, 5, 5, 7 };
    cout << lower_bound(v, 2) << '\n'; // 1
    cout << upper_bound(v, 2) << '\n'; // 4
    cout << "2의 개수 : " << upper_bound(v, 2) - lower_bound(v, 2) << '\n'; // 3

    cout << lower_bound(v, 4) << '\n'; // 4
    cout << upper_bound(v, 4) << '\n'; // 4
    cout << "4의 개수 : " << upper_bound(v, 4) - lower_bound(v, 4) << '\n'; // 0

    return 0;
}