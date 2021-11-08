def middle(str):
    # 문자 길이 변수
    value = len(str)
   
    # 홀수
    if value % 2 == 1:
        return str[int(value / 2)]
   
    # 짝수 
    else:
        return str[int(value / 2) - 1] + str[int(value / 2)]


print("-------------------------")
print("middle()")
print(middle("나는문어"))
print(middle("나는감자"))
print(middle("pypypyp"))


# ----------------------------------------------------------------

def countVowles(s):
    text = "모음의 총 개수: "
    # 합 변수
    sum = 0
    
    for i in s:
        # 조건 검사
        if i.lower() in ['a', 'e', 'i', 'o', 'u']:
            sum += 1
   
    # 결과 반환
    return text + str(sum)


print("-------------------------")
print("countVowles()")
print(countVowles("I am Groot!"))
print(countVowles("Why not change the world!"))
print(countVowles("Hello World"))


# ----------------------------------------------------------------

def reverse(text):
    # return 변수
    out = ''

    # 뒤에서 부터 시작하는 반복문
    for i in range(len(text) - 1, -1, -1):
        out += text[i]
    
    # 결과 반환
    return out


print("-------------------------")
print("reverse()")
print(reverse("Python"))
print(reverse("나는문어"))
print(reverse("어문는나"))
