n = int(input())
while n != 0:
    valores = input().split()
    inflexao = 0
    subts = {}

    for i in range(n):
        if i == n - 1:
            subts[i - 1] = int(valores[i]) - int(valores[i - 1])
            subts[i] = int(valores[0]) - int(valores[i])
        else:
            if i > 0:
                subts[i - 1] = int(valores[i]) - int(valores[i - 1])

    if (subts[len(subts)-1] > 0 and subts[0] < 0) or (subts[len(subts)-1] < 0 and subts[0] > 0):
        inflexao += 1

    for j in range(len(subts)):
        if j > 0:
            if (subts[j] > 0 and subts[j - 1] < 0) or (subts[j] < 0 and subts[j - 1] > 0):
                inflexao += 1

    print(inflexao)
    n = int(input())
