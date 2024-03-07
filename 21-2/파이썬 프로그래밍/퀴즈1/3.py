# 입력
value1 = int(input("첫번째 수를 입력하세요 : "))
value2 = int(input("두번째 수를 입력하세요 : "))
k = 0  # for 문 내부 증가율 변수
index = 0  # for index
result = 0  # 결과 출력 변수
# 입력 에러 검사
if value2 == value1:
    print("입력 에러입니다")
elif (value1 <= 0) or (value2 <= 0):
    print("양의 정수가 아니라서 입력 에러입니다")
else:  # 에러가 아니라면
    # 증가율 지정
    if value2 < value1:
        k = -1
    else:
        k = 1
    # 연산, 출력 반복문
    for i in range(value1, value2, k):
        if index % 2 == 0:  # 짝수번째 반복일 때
            print(str(i) + " -", end=" ")
            result += i
        else:  # 홀수번째 반복일 때
            print(str(i) + " +", end=" ")
            result -= i
        index += 1
    # 마지막 연산
    if index % 2 == 1:
        result -= value2
    else:
        result -= value2
    # 출력
    print(str(value2) + " =", result)
