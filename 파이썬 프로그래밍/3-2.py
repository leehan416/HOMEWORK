list = [44, 93, 44, 33, 44, 22, 35, 53, 82, 52, 32, 63, 83, 66, 72, 58, 49, 25, 62, 13, 58, 63, 57, 63, 34, 14, 50, 41,
        18, 56]

maxValue = 0  # 최대 반복 횟수 저장 변수
maxNum = []  # 결과 출력용 리스트

for i in list:  # 전체 반복
    count = 0  # 반복 횟수 초기화
    for j in list:  
        if i == j:  # 반복 검사
            count += 1 
    if maxValue < count:  # 만약 반복횟수가 이전 최대 반복 횟수 보다 크다면
        # 변수들 초기화
        maxNum = []  
        maxValue = count  
        maxNum.append(i)
    elif maxValue == count:  # 반복횟수가 동일하다면
        # 출력 변수에 추가
        if i in maxNum:  # 만약 이미 존재하는 수 이라면
            continue  
        else:
            maxNum.append(i)
# 결과 출력
print(maxNum, str(maxValue) + "회 반복됨")
