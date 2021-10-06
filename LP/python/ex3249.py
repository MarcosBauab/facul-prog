n = int(input())
vitorias = 0
for i in range(n):
    poderes = input()
    perdeu = False
    for c in range(len(poderes)):
        if c > 0:
            if poderes[c - 1] == 'C' and poderes[c] == 'D':
                perdeu = True
    if perdeu == False:
        vitorias += 1
print(vitorias)