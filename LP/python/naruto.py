while True:
    try:
        num1 = int(input())
        j = 0
        if num1 == 1:
            print(j)
        else:
            while num1 != 1:
                num1 = num1 / 2
                j = j + 1
            print(j)
    except:
        break






import math

while (True):
    try:
        num1 = int(input())
        if (num1 >= 1 and num1 <= 10 ** 6):
            logou = math.log2(num1)
            print("{:.0f}".format(logou))
    except:
        break
