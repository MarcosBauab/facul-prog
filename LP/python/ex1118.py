t = 0
while t != 2:
    i = 0
    c = 0
    while i == 0:
        t = 0
        num1 = float(input())
        if num1 < 0 or num1 > 10:
            print("nota invalida")
        else:
            i = 1
    while c == 0:
        num2 = float(input())
        if num2 < 0 or num2 > 10:
            print("nota invalida")
        else:
            c = 1

    media = (num1 + num2) / 2
    print("media = {:.2f}".format(media))

    while t == 0:
        print("novo calculo (1-sim 2-nao)")
        num3 = int(input())
        if num3 == 2:
            t = 2
            break
        elif num3 == 1:
            i = 0
            c = 0
            break
        else:
            t = 0