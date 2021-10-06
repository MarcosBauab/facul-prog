R,N = input().split()
i = 0
while R != '0' and N != '0':
    alfabeto = (int(N) * 26) + int(N)
    if int(R) > alfabeto:
        print("Case {}: impossible".format(i + 1))
        i += 1

    if R == N:
        print("Case {}: 0".format(i + 1))
        i += 1

    divisao = int(R)/int(N)
    if int(R) % int(N) == 0:
        print("Case {}: {}".format(i + 1, int(divisao) - 1))
        i += 1
    else:
        print("Case {}: {}".format(i + 1, int(divisao)))
        i += 1
    R, N = input().split()