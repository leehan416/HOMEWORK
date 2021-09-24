# 변수선언, 입력
num1 = int(input()) 
num2 = int(input())
sum = 0 # 결과값 

# 더 큰수를 num2로 변경
if (num2 < num1): 
    # swap
    temp = num1
    num1 = num2
    num2 = temp

# 수를 더하기 위한 반복문
for i in range(num1, num2 + 1): # num1 ~ num2 반복
    sum += i

#결과 출력
print(sum)
