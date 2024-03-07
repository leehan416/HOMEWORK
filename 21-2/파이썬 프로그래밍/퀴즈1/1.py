# 입력
value = int(input("수를 입력하세요 : "))

if value == 0:  # 변수가 0 이라면
    print("0입니다")
elif value % 3 == 0:  # 변수가 3의 배수라면
    if value % 2 == 1:  # 홀수
        print("3의 배수인 홀수입니다")
    else:
        print("3의 배수인 짝수 입니다")
else:  # 3의 배수가 아니라면
    if value % 2 == 1:  # 홀수
        print("홀수입니다")
    else:
        print("짝수 입니다")
