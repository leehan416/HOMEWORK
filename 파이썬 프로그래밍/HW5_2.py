import random

# 랜덤 숫자 배열 정의
comlist = random.sample(range(0, 10), 4)
# 시도 횟수
count = 0

## test
# print(comlist)

# 중복 검사
def check_list(list, input_num):
    if input_num in list:
        return True
    else:
        return False


# strike 횟수
def countStrike(list):
    out = 0
    for i in range(4):
        # 위치, 값 모두 같다면
        if comlist[i] == list[i]:
            out += 1

    # 결과 반환
    return out


# ball 횟수
def countBall(list):
    out = 0
    for i in range(4):
        # 위치는 다르지만, 값이 같다면
        if (comlist[i] != list[i]) and list[i] in comlist:
            out += 1

    # 결과 반환
    return out

while True:
    # 횟수 증가
    count += 1

    # 유저 입력 리스트 초기화
    userlist = []

    while len(userlist) < 4:
        try:
            # 변수 입력
            value = int(input("Input a number : "))

            # 입력 검사
            if (0 > value) and (value > 9):
                # 잘못된 입력
                print("Please input a number from 0 to 9")
            elif check_list(userlist, value):
                # 중복
                print("Duplicate number")
            else:
                # 올바른 입력
                userlist.append(value)
        except ValueError: # 숫자가 아니라면
            print("error")
    # 횟수 검사
    stri = countStrike(userlist)

    # 결과 출력
    print(stri, "strike,", countBall(userlist), "  ball\n")

    # 모두 맞았다면
    if stri == 4:
        # 반복문 나가기
        break

# 승리
print("You win! on ", count, " try..")
