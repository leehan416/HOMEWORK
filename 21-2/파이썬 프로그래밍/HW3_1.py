word = ['apple', 'axes', 'book', 'box', 'buzz', 'cat', 'cantus', 'church', 'dish', 'knife', 'lady', 'leaf', 'pitch',
        'stimulus', 'taxi', 'wish', 'wolf']
plural = []

for i in word:  # 조건 a
    if i[-1] == "y":
        plural.append((i[0:len(i) - 1] + "ies"))  # y 제외하고 ies 붙이기
    elif i[-1] == "f" or i[-2:] == "fe":  # 조건 b
        if i[-1] == "e":  # e
            plural.append((i[0:len(i) - 2] + "ves"))  # e 를 제외하고 ves 붙이기
        else:  # fe
            plural.append((i[0:len(i) - 1] + "ves"))  # fe 를 제외하고 ves 붙이기
    elif i[-2:] == "us":  # 조건 c
        plural.append((i[0:len(i) - 2] + "i"))  # us 를 제외하고 i 붙이기

    elif i[-1] == "s" or i[-1] == "x" or i[-1] == "z" or i[-2:] == "ch" or i[-2:] == "sh":  # 조건 d
        plural.append((i + "es")) # 뒤에 es 붙이기

    else:  # 조건 e
        plural.append((i + "s")) # 뒤에 s 붙이기

print(plural)