# insira sua resposta aqui
salario = 2000
ano = 2016
mes = 10
divida = 100

while salario >= divida:
    mes += 1
    divida += 0.15 * divida
    if mes == 12:
        ano += 1
        mes = 0
    elif mes == 3:
        salario += 0.05 * salario

print("A dívida do cartão de crédito de Pedro será superior ao seu salário no mês {} e ano {}.\n\
    O salário de Pedro será R${} e sua dívida será R${}".format(mes, ano, round(salario, 2), round(divida, 2)))
