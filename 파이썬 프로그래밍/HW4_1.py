list = ['O', 'S', 'C', 'H', 'N']  # 원자
listData = [15.9994, 32.066, 12.011, 1.00794, 14.00674]  # 분자량
sum = 0.0  # 결과 변수

# 변수 입력
userInput = input("화학식을 입력 하시오 : ")
userInput = userInput.upper()
for i in range(len(userInput)):
    if userInput[i] in list:  # 리스트에 포함된 원자일 때에만 진행 (숫자 통과)
        if i == len(userInput) - 1:  # last index
            sum += listData[list.index(userInput[i])]
        else:
            try:  # 다음 문자열이 숫자라면
                # 숫자와 분자량을 곱하여 더함
                sum += listData[list.index(userInput[i])] * int(userInput[i + 1])
            except ValueError:  # 숫자가 아니라면
                # 분자량을 더함
                sum += listData[list.index(userInput[i])]
    else:
        try:  # 문자열이 숫자라면
            int(userInput[i])
            continue
        except ValueError:  # 숫자가 아니라면
            print("존재하지 않는 데이터 입니다")
            exit()

print(userInput + "의 분자량은", sum)
