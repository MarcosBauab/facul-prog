risada = list(input())
vogais = ['a','e','i','o','u']
palavra = ''
for letra in risada:
    for i in range(len(vogais)):
        if letra == vogais[i]:
            palavra += vogais[i]

tam = len(palavra)
inversa = ''
while tam != 0:
    inversa += palavra[tam - 1]
    tam -= 1

if palavra == inversa:
    print("S")
else:
    print("N")