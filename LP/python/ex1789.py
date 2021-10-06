while True:
    try:
        n = int(input())
        if n >= 1 and n <= 500:
            nums = input().split()
            if len(nums) != n:
                print('erro')
            else:
                maior = 0
                for i in nums:
                    i = int(i)
                    if i > maior:
                        maior = i
                if maior < 10:
                    print("1")
                elif maior >= 10 and maior < 20:
                    print("2")
                else:
                    print("3")
    except:
        break