# 3
import random


# dice 함수 구현
def dice():
    return random.randint(1, 10)


# 변수 초기화
a = dice()
b = dice()
c = dice()

# 출력
# print(a, b, c) # test
print("a: " + str(a), ",", "c: ", str(c), ",", "(a + b) * c:", str((a + b) * c))

# 맞았다면 False
check = True

# 정답 입력 반복문
for i in range(3):
    # 입력
    try:
        userInput = int(input("b 값을 입력하세요: "))
    # 잘못된 입력
    except ValueError:
        print("value Error")
        exit()
    else:
        # 맞았다면
        if userInput == b:
            check = False
            print("맞았습니다")
            break
        # 틀렸다면
        else:
            print("틀렸습니다. 다시 입력하세요")
# 맞추지 못했다면
if check:
    print("정답을 찾지 못하고 종료, b는", str(b), "입니다")
