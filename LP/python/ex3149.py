P,Q = input().split()
P = int(P) / 100
baixo = 23.60 - P
cima = 24.00 + P
info = []
verdadeiros = []
for i in range(int(Q)):
    individual = []

    horario, nome = input().split()
    horario = horario.replace(":",".")
    if float(horario) < 23:
        horario = horario.replace("00.", "24.")

    individual.append(horario)
    individual.append(i)
    individual.append(nome)
    info.append(individual)

    info.sort()

for i in range(int(Q)):
    if (float(info[i][0]) >= baixo) and (float(info[i][0]) <= cima):
        verdadeiros.append(info[i][2])

for nome in verdadeiros:
    print(nome)