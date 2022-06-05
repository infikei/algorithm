// boj_10845.cpp 코드에서 배열 길이만 바꿔준 버전

#include <iostream>
#include <string>
using namespace std;

int q_begin = 0, q_end = 0;
int q[2000001];

void push(int x)
{
    q[q_end] = x;
    q_end++;
}

int pop()
{
    if (q_begin == q_end)
        return -1;
    q_begin++;
    return q[q_begin - 1];
}

int size()
{
    return q_end - q_begin;
}

int empty()
{
    if (q_begin == q_end)
        return 1;
    return 0;
}

int front()
{
    if (q_begin == q_end)
        return -1;
    return q[q_begin];
}

int back()
{
    if (q_begin == q_end)
        return -1;
    return q[q_end - 1];
}

int main()
{
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int n, input;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> input;
            push(input);
        }
        else if (cmd == "pop")
            cout << pop() << "\n";
        else if (cmd == "size")
            cout << size() << "\n";
        else if (cmd == "empty")
            cout << empty() << "\n";
        else if (cmd == "front")
            cout << front() << "\n";
        else if (cmd == "back")
            cout << back() << "\n";
    }

    return 0;
}