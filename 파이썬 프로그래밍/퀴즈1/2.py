# 입력
value = int(input("수를 입력하세요 : "))
result = 1  # 결과값 변수

for i in range(value, 0, -1):  # 연산, 결과 출력 반복문
    result = 1  # 결과값 초기화
    for j in range(i, 0, -1):  # 연산
        result *= j
    # 결과물 가독성을 위한 조건문
    if i == 1:
        print(result, end=" ")  # 결과 출력
    else:
        print(str(result) + ", ", end=" ")  # 결과 출력
