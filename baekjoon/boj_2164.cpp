#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.

    int N, card;
    cin >> N;

    queue<int> q;

    for (int i = 1; i <= N; i++)
        q.push(i);

    bool pop = true;

    while (q.size() > 1)
    {
        if (pop)
        {
            q.pop();
            pop = false;
        }
        else
        {
            card = q.front();
            q.pop();
            q.push(card);
            pop = true;
        }
    }

    cout << q.front() << "\n";

    return 0;
}