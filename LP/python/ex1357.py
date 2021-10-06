D = int(input())

braille = [['.*','*.','*.','**','**','*.','**','**','*.','.*'],
           ['**','..','*.','..','.*','.*','*.','**','**','*.'],
           ['..','..','..','..','..','..','..','..','..','..']]

while D != 0:
    formato = input()
    #matriz = []
    if formato.lower() == 's':
        digitos = list(input())
        for i in range(len(braille)):
            for j in range(len(braille[0])):
                for digito in digitos:
                    if int(digito) == j:
                        print(braille[i][j], end=' ')
            print()
    elif formato.lower() == 'b':
        recebe = []
        for i in range(3):
            B = input().split()
            recebe.append(B)
        for j in range(len(recebe[0])):
            for coluna in range(len(braille[0])):
                if recebe[0][j] == braille[0][coluna]:
                    if recebe[1][j] == braille[1][coluna]:
                        if recebe[2][j] == braille[2][coluna]:
                            print(coluna, end='')
        print()
    D = int(input())

#for i in range(len(matriz[0])):
    #for j in range(len(matriz)):
     #   print(matriz[j][i], end=' ')
    #print()