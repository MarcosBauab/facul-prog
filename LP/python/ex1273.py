x = int(input())
while x != 0:
    str = []
    maior = ""
    for i in range(x):
        str.append(input())
        if i > 0:
            if len(str[i]) > len(str[i - 1]):
                maior = str[i]
            else:
                maior = str[i - 1]
    for i in range(len(str)):
        if len(str[i]) != len(maior):
            sub = len(maior) - len(str[i])
            str[i] = (sub * ' ') + str[i]
        print(str[i])
    print()
    x = int(input())
