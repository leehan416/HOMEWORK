# 1번

# A
def ispal(value):
    # 알파벳만 있는 문자열로 변환
    value = value.lower()
    val = value.split(" ")

    value = ''

    for i in val:
        for j in i:
            if j.isalpha():
                value += j

    # 검사
    n = len(value)
    for i in value:
        n -= 1
        if value[n] != i:
            return False
    return True

# B
def transfer(value):
    m = {
        "A": "Z", "B": "Y", "C": "X", "D": "W", "E": "V", "F": "U", "G": "T", "H": "S", "I": "R", "J": "Q", "K": "P",
        "L": "O", "M": "N",
        "N": "M", "O": "L", "P": "K", "Q": "J", "R": "I", "S": "H", "T": "G", "U": "F", "V": "E", "W": "D", "X": "C",
        "Y": "B", "Z": "A",
    }

    val = ''
    for i in str(value):
        # 만약 알파벳이 아니면 그냥 더하기
        if not i.isalpha():
            val += i
            continue
        
        # 대소문자 구분하여 변환
        if i.islower():
            val += m[i.upper()].lower()
        else:
            val += m[i.upper()]
    return val

# 입력
try:
    userInput = str(input("문자열 입력 : "))
# 잘못된 입력
except ValueError: 
    print("value Error")
# 결과 출력
else:
    if ispal(userInput):
        print(userInput + "은 PALINDROME이며, 변환 후", transfer(userInput), "입니다.")
    else:
        print(userInput + "은 PALINDROME이 아니며, 변환 후", transfer(userInput), "입니다.")
