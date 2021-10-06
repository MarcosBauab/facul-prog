
valor = int(input())
print(valor)
cedulas = [100, 50, 20, 10, 5, 2, 1]

for cedula in cedulas:
    divisao = int(valor / cedula)
    print("{0} nota(s) de R$ {1:.2f}".format(divisao, cedula))
    valor -= divisao * cedula

qtd = int(input())
print(qtd)

cem = int(qtd / 100)
print("{} nota(s) de R$ 100,00".format(cem))
qtd -= cem * 100

cinquenta = int(qtd / 50)
print("{} nota(s) de R$ 50,00".format(cinquenta))
qtd -= cinquenta * 50
