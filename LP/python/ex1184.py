O = input()

matriz = []
for i in range(12):
    individual = []
    for j in range(12):
        individual.append(float(input()))
    matriz.append(individual)

certos = []
for i in range(12):
    for j in range(12):
        if j < i:
            certos.append(matriz[i][j])

num = 0
for i in range(len(certos)):
    num += certos[i]

if O.lower() == 's':
    print(round(num, 1))
elif O.lower() == 'm':
    print(round(num / len(certos), 1))