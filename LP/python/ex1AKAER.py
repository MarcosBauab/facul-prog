def peca_faltante(Q):
    n = len(Q)
    total = (n + 1) * (n + 2) / 2
    sum_of_pecas = sum(Q)
    return total - sum_of_pecas

N = int(input())
valores = input().split()
for i in range(len(valores)):
    valores[i] = int(valores[i])

miss = peca_faltante(valores)
print(f"{miss:.0f}")
