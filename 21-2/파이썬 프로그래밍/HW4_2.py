def getNum(n):
    return 4 / (2 * n - 1)


# 결과 연산 변수
sum = 0.0
# 항 제어 변수
index = 1

# 변수 입력
userInput = float(input("오차값을 실수로 입력하세요: "))

if userInput > 0.01:  # 0.01 이상의 수가 입력되었다면
    print("0.01 이하 값만 입력하세요.")
    exit()

value = getNum(index)  # 초기 항 연산
while value > userInput:
    if index % 2 == 1:  # 홀수
        sum += value
    else:  # 짝수
        sum -= value
    index += 1  # 항 증가
    value = getNum(index)  # 다음 항

print(sum)  # 결과 출력
