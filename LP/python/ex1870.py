L, C, P = input().split()
while C != '0' and L != '0':
    matriz = []
    for i in range(int(L)):
        linha = input().split()
        matriz.append(linha)
    boom = False
    for i in range(int(L)):
        j = int(P) - 2
        while j >= 0:
            if matriz[i][j] != '0':
                potEsq = int(matriz[i][j])
                posEsq = j
                break
            j -= 1
        j = int(P)
        while j <= int(C):
            if matriz[i][j] != '0':
                potDir = int(matriz[i][j])
                posDir = j
                break
            j += 1

        sub = abs(potDir - potEsq)
        if potDir > potEsq:
            P = int(P) - sub
        elif potEsq > potDir:
            P = int(P) + sub

        if int(P)-1 <= posEsq:
            print("BOOM {0} {1}".format(i + 1, posEsq + 1))
            boom = True
        elif int(P)-1 >= posDir:
            print("BOOM {0} {1}".format(i + 1, posDir + 1))
            boom = True
    if boom == False:
        print("OUT {}".format(P))
    L, C, P = input().split()