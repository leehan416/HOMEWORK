# 변수 선언, 변수 입력
score = float(input("Input your score : "))
mode = input("Input Letter(L) or PF(PF) : ")
output = ""  # 결과 출력 변수

# 점수에 맞는 output 지정
if 90 < score and score <= 100:  # 90초과 100 이하
    if mode == "L":
        output = "A"
    else:
        output = "PD(Pass with Distinction)"
elif 80 < score and score <= 90:  # 80초과 90 이하
    if mode == "L":
        output = "B"
    else:
        output = "Pass"
elif 70 < score and score <= 80:  # 70초과 80 이하
    if mode == "L":
        output = "C"
    else:
        output = "Pass"
elif 60 < score and score <= 70:  # 60초과 70 이하
    if mode == "L":
        output = "D"
    else:
        output = "Pass"
elif score <= 60:  # 60 이하
    if mode == "L":
        output = "F"
    else:
        output = "Fail"
        
print(output)  # 결과 출력
