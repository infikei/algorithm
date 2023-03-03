# eval(expression) 함수는 문자열로 구성된 표현식 expression을 입력 값으로 받으며, 해당 문자열을 실행한 결과값을 반환한다.
python_1 = "print('Hello, World!', 22 + 5)"
eval(python_1) # Hello, World! 27

# id(obj) 함수는 객체 obj를 입력 값으로 받아 객체의 고유 주소 값(레퍼런스)을 반환한다.
# 아래 코드에서 3, a, b의 고유 주소 값이 모두 같게 나온다. 이는 3, a, b가 모두 같은 객체를 가리키고 있기 때문이다. 4는 3, a, b와 다른 객체이므로 당연히 다른 고유 주소 값이 출력된다.
a = 3
print(id(3))
print(id(a))
b = a
print(id(b))
print(id(4))

# isinstance(obj, class) 함수는 객체 obj와 클래스 class를 입력 값으로 받으며,
# 입력으로 받은 객체가 입력으로 받은 클래스의 인스턴스이면 True를, 아니면 False를 반환한다.
class Person: pass

a = Person()
res1 = isinstance(a, Person)
b = 3
res2 = isinstance(b, Person)
print([res1, res2]) # [True, False]

print("=" * 30)





# len(s) 함수는 입력 값 s의 길이를 반환한다.
res1, res2, res3 = len("python"), len([1, 2, 3]), len((1, "ab"))
print([res1, res2, res3]) # [6, 3, 2]

# int(n) 함수는 문자열 형태의 숫자나 소수점이 있는 숫자 n을 입력 값으로 받아 정수로 반환한다.
# 만약 정수가 입력 값으로 들어오면 그대로 반환한다.
num1, num2 = int("3"), int(3.4)
print([num1, num2]) # [3, 3]

# str(obj) 함수는 문자열 형태로 객체를 변환하여 반환한다.
# 만약 문자열이 입력 값으로 들어오면 그대로 반환한다.
s, s2 = str(3), str("python")
print([s, s2]) # ["3", "python"]

# list(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받아 리스트로 만들어 반환한다.
# 만약 list가 입력 값으로 들어오면 똑같은 리스트를 복사하여 반환한다.
li, li2 = list("python"), list((1, 2, 3))
print(li, li2) # ["p", "y", "t", "h", "o", "n"] [1, 2, 3]
li3, li4 = li2, list(li2)
print(li3, li4) # [1, 2, 3] [1, 2, 3]
print(id(li2), id(li3), id(li4)) # li2와 li3는 같은 객체를 가리키며, li4는 다른 객체를 가리키고 있다.

# tuple(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받아 튜플로 변환하여 반환한다.
# 만약 튜플이 입력 값으로 들어오면 그대로 반환한다.
li, li2 = tuple("python"), tuple([1, 2, 3])
print(li, li2) # ("p", "y", "t", "h", "o", "n") (1, 2, 3)

# type(obj) 함수는 입력 값의 자료형이 무엇인지를 알려주는 함수이다.
print(type(3), type(3.14), type("python")) # <class 'int'> <class 'float'> <class 'str'>
print(type([]), type(()), type({})) # <class 'list'> <class 'tuple'> <class 'dict'>
print(type(set())) # <class 'set'>

print("=" * 30)





# enumerate는 "열거하다"라는 의미로, enumerate(li) 함수는 순서가 있는 데이터(리스트, 튜플, 문자열) li를 입력 값으로 받아 인덱스 값을 포함하는 enumerate 객체를 반환한다.
li = ["body", "foo", "bar"]
print(list(enumerate(li))) # [(0, "body"), (1, "foo"), (2, "bar")]
for idx, item in enumerate(li):
    print(idx, item)

# all(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받으며,
# 이 li의 요소들이 모두 참이면 True를, 요소들 중 거짓이 하나라도 있으면 False를 반환한다.
# 만약 li가 빈 값일 경우에는 True를 반환한다.
res1, res2, res3 = all([3, 5, 1]), all([3, 5, 0]), all([])
print(res1, res2, res3) # True False True

# any(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받으며,
# 이 li의 요소들 중 참이 하나라도 있으면 True를, 요소들이 모두 거짓이면 False를 반환한다.
# 만약 li가 빈 값일 경우에는 False를 반환한다.
res1, res2, res3 = any([3, 5, 0]), any([0, "", []]), any([])
print(res1, res2, res3) # True False False

# max(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받아 그 최댓값을 반환한다.
# min(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받아 그 최솟값을 반환한다.
# sum(li) 함수는 반복 가능한(iterable) 데이터 li를 입력 값으로 받아 각 데이터들의 합을 반환한다.
res1, res2 = max([1, 2, 3]), max("python")
print([res1, res2]) # [3, "y"]
res1, res2 = min([1, 2, 3]), min("python")
print([res1, res2]) # [1, "h"]
res1, res2 = sum([1, 2, 3]), sum((4, 5, 6))
print([res1, res2]) # [6, 15]

# filter(func, li) 함수는 함수 func과 반복 가능한(iterable) 데이터 li를 입력 값으로 받으며,
# 데이터의 각 요소마다 함수 func를 호출했을 때 반환 값이 참인 요소만 묶어서 filter 객체로 반환한다.
li = list(filter(lambda x: x > 0, [3, 5, 2, 0, -4, -6, 7]))
print(li) # [3, 5, 2, 7]

# map(func, li) 함수는 함수 func과 반복 가능한(iterable) 데이터 li를 입력 값으로 받으며,
# 데이터의 각 요소마다 함수 func를 호출하여 적용한 결과를 map 객체로 반환한다.
li = list(map(lambda x: x * 2, [1, 2, 3, 4]))
print(li) # [2, 4, 6, 8]

# zip(*iterable) 함수는 동일한 개수로 이루어진 데이터 여러 개를 묶어서 zip 객체로 반환한다.
li = list(zip([1, 2, 3], [4, 5, 6]))
print(li) # [(1, 4), (2, 5), (3, 6)]
li = list(zip([1, 2, 3], [4, 5, 6], [7, 8, 9]))
print(li) # [(1, 4, 7), (2, 5, 8), (3, 6, 9)]
li = list(zip("abc", "def"))
print(li) # [("a", "d"), ("b", "e"), ("c", "f")]

print("=" * 30)





# sorted(li) 함수는 입력 값으로 받은 데이터 li를 정렬한 후 그 결과를 리스트로 반환한다.
# sorted(li, reverse=True) 형태로 함수를 호출하면 데이터 li를 내림차순으로 정렬한 후 그 결과를 리스트로 반환한다.
li, li2 = sorted([3, 1, 2]), sorted((3, 1, 2))
print(li, li2) # [1, 2, 3] [1, 2, 3]
li3, li4 = sorted(["a", "c", "b"]), sorted("zero")
print(li3, li4) # ["a", "b", "c"] ["e", "o", "r", "z"]

li, li2 = sorted([3, 1, 2], reverse=True), sorted((3, 1, 2), reverse=True)
print(li, li2) # [3, 2, 1] [3, 2, 1]
li3, li4 = sorted(["a", "c", "b"], reverse=True), sorted("zero", reverse=True)
print(li3, li4) # ["c", "b", "a"] ["z", "r", "o", "e"]

# 참고로 list 자료형에도 리스트를 정렬해주는 sort 함수가 있는데, 해당 함수는 리스트 객체 그 자체를 정렬만 할 뿐 그 결과를 반환하지는 않는다.
li, li2 = [3, 1, 2], [3, 1, 2]
li.sort()
li2.sort(reverse=True)
print(li, li2) # [1, 2, 3] [3, 2, 1]

# reversed(li) 함수는 입력 값으로 받은 데이터 li의 요소들을 역순으로 뒤집은 결과를 reversed 객체로 반환한다.
li, li2, li3 = list(reversed([3, 1, 2])), tuple(reversed((3, 1, 2))), list(reversed(["a", "c", "b"]))
print(li, li2, li3) # [2, 1, 3] (2, 1, 3) ["b", "c", "a"]

# 참고로 list 자료형에도 리스트의 요소들을 역순으로 뒤집는 reverse 함수가 있는데, 해당 함수는 리스트 객체 그 자체를 뒤집을 뿐 그 결과를 반환하지는 않는다.
li = [3, 1, 2]
li.reverse()
print(li) # [2, 1, 3]

print("=" * 30)





# divmod(a, b) 함수는 2개의 숫자 a, b를 입력 값으로 받아 a를 b로 나눈 몫과 나머지를 튜플로 반환한다.
res1 = divmod(7, 3)
res2 = (7 // 3, 7 % 3) # 위의 코드와 결과가 같다.
print([res1, res2]) # [(2, 1), (2, 1)]

# pow(x, y) 함수는 x의 y제곱 값을 반환한다.
num1, num2 = pow(2, 4), pow(3, 3)
print([num1, num2]) # [16, 27]

# round(n[, ndigits]) 함수는 숫자를 입력받아 반올림하여 반환한다.
# [, ndigits]는 ndigits가 있을 수도 있고 없을 수도 있다는 의미이다. ndigits에는 반올림하여 표시하고 싶은 소수점의 자릿수를 입력한다.
num1, num2, num3 = round(4.6), round(4.2), round(5.678, 2)
print([num1, num2, num3]) # [5, 4, 5.68]

# int(n, radix)는 radix 진수로 표현된 문자열 n을 입력 값으로 받아 10진수로 변환한 값을 반환한다.
num1, num2, num3 = int("11", 2), int("0xea", 16), int("0o352", 8)
print([num1, num2, num3]) # [3, 234, 234]

# hex(n) 함수는 정수 n을 입력 값으로 받아 16진수 문자열을 반환한다.
# oct(n) 함수는 정수 n을 입력 값으로 받아 8진수 문자열을 반환한다.
num1, num2 = hex(234), oct(234)
print([num1, num2]) # ["0xea", "0o352"]

# chr(n) 함수는 유니코드 숫자값 n을 입력 값으로 받아 그 코드에 해당하는 문자를 반환한다.
# ord(c) 함수는 입력 값으로 받은 문자 c의 유니코드 숫자 값을 반환한다.
a, b = chr(97), chr(44032)
print([a, b]) # ["a", "가"]
a, b = ord("a"), ord("가")
print([a, b]) # [97, 44032]

print("=" * 30)
