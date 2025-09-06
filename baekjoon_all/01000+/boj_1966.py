# Solve 2023-03-01
# Update 2025-09-05

import sys
from collections import deque, Counter

input = lambda: sys.stdin.readline().rstrip()

def solution(m, documents):
    counter = Counter(documents)
    deq = deque()

    for i in range(len(documents)):
        deq.append((documents[i], i))

    ans = 0

    for v in range(9, 0, -1):
        while counter[v] > 0:
            cur_doc = deq.popleft()

            if cur_doc[0] == v:
                counter[v] -= 1
                ans += 1

                if cur_doc[1] == m:
                    return ans
            else:
                deq.append(cur_doc)


for _ in range(int(input())):
    _, m = map(int, input().split())
    documents = list(map(int, input().split()))
    print(solution(m, documents))
