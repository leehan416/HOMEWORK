map = [
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0]
]

x = 3
y = 0

for i in range(pow(len(map), 2)):

    map[y][x] = i + 1

    if (i + 1) % len(map) == 0:
        y += 1
    else:
        x -= 1
        y -= 1

    if y < 0:
        y = 6
    elif y > 6:
        y = 0

    if x < 0:
        x = 6
    elif x > 6:
        x = 0

for i in map:
    print(i)
