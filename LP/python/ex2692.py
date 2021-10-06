n = input().split()
letras = []
frases = []
frasePronta = {}
str = ""

for i in range(int(n[0])):
    letras.append(input().split())
for i in range(int(n[1])):
    frases.append(input())

def mudarLetra(parm):
    for i in range(int(n[0])):
        if parm == letras[i][0]:
            return letras[i][1]
            break
        elif parm == letras[i][1]:
            return letras[i][0]

for i in range(int(n[1])):
    str = ""
    #pega a frase individual
    for letra in frases[i]:
        for c in range(int(n[0])):
            #compara com as letras recebidas
            if letra == letras[c][0] or letra == letras[c][1]:
                letra = mudarLetra(letra)
        str += letra
        frasePronta[i] = str

for i in range(len(frasePronta)):
    print(frasePronta[i])
