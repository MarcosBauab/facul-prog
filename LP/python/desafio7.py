vet = [1,2,3,4]

def deslocamento_x(x):
    for i in range(len(vet)):
        vet[i] = vet[i] + x

x = int(input("Insira o valor de x : "))
deslocamento_x(x)
print(vet)