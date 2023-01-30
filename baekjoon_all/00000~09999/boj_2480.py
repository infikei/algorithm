a, b, c = map(int, input().split())
print((a+10)*1000 if a == b == c else ((a+10)*100 if a == b or a ==
                                       c else ((b+10)*100 if b == c else (max([a, b, c])*100))))
