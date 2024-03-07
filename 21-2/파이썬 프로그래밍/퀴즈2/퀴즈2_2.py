# 2번

def fac(value):
    if value == 0:
        return 1
    else:
        return fac(value - 1) * value

# 입력
try:
    userInput = int(input("정수를 입력하세요 : "))
# 잘못된 입력
except ValueError:
    print("value Error")
# 결과출력
else:
    print(str(userInput) + "!", "=", fac(userInput))
