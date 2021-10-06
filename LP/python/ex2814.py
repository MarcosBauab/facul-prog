casos = int(input())
for i in range(casos):
    K,J = input().split()
    matriz = []
    for i in range(int(J)):
        linha = list(input())
        matriz.append(linha)
        for j in range(len(matriz[i])):
            if matriz[i][j] == 'F':
                linha_F = i
                coluna_F = j
            if matriz[i][j] == 'J':
                linha_J = i
                coluna_J = j

    subt_linhas = abs((10 * (linha_J - linha_F)))
    subt_colunas = abs((10 * (coluna_J - coluna_F)))

    hipotenusa = int(((subt_colunas ** 2) + (subt_linhas ** 2)) ** (1/2))
    somMax = int(int(K) / (0.99 ** hipotenusa))

    print(somMax, "dBs")