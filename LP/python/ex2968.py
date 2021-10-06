v = list(map(int, input().split()))
i = 10
while i <= 90:
    mult = v[0] * v[1]
    porc = mult * (i / 100)
    if porc > int(porc):
        print(int(porc) + 1, end=' ')
    else:
        print(int(porc), end=' ')
    i += 10