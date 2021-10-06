def busca(parm: list, valor):
    achei = None
    for i in range(len(parm)):
        if valor == parm[i]:
            achei = i
            return achei
    if achei == None:
        return 'Valor não encontrado'

def maiorElemento(parm: list):
    parm.sort()
    maior = parm[-1]
    return maior

def soma(parm: list):
    soma = 0
    for i in range(len(parm)):
        soma += parm[i]
    return soma

lista = [5,4,7,2,1]

print("Busca: ",busca(lista, 1))
print("Maior: ",maiorElemento(lista))
print("Soma: ",soma(lista))