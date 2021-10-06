num = int(input())
i = 0
tipos = {'X': 0, 'H': 0, 'E': 0, 'A': 0, 'M': 0}

while i < num:
    nome = input().split()
    for letra in tipos:
        if nome[1] == letra:
            tipos[letra] += 1
    i += 1

print("{0} Hobbit(s)".format(tipos['X']))
print("{0} Humano(s)".format(tipos['H']))
print("{0} Elfo(s)".format(tipos['E']))
print("{0} Anao(s)".format(tipos['A']))
print("{0} Mago(s)".format(tipos['M']))
