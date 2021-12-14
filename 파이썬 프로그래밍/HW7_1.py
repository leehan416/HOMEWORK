
# A
def sorted(n1, n2, n3, n4):
    inp = [int(n1), int(n2), int(n3), int(n4)]
    inpu = [int(n1), int(n2), int(n3), int(n4)]
    inp.sort()
    if inp == inpu:
        return True
    else:
        return False


print(sorted(1, 5, 3, 4))
print(sorted(1, 2, 3, 4))

# B
def numDigit(n):
    l = str(n).split(".")
    print("정수 자리 수", len(l[0]), "소수 자리 수", len(l[1]))


numDigit(123.123123)
numDigit(1242423.12)
