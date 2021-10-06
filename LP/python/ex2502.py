while True:
    try:
        n = input().split()
        trocas = []
        frases = []
        for i in range(2):
            trocas.append(input())
        for i in range(int(n[1])):
            frases.append(input())


        for i in range(int(n[1])):
            str = ""
            #pega a frase individual
            for letra in frases[i]:
                for c in range(int(n[0])):
                    if letra.upper() == letra.lower():
                        if letra == trocas[0][c]:
                            letra = trocas[1][c].lower()
                        elif letra == trocas[1][c]:
                            letra = trocas[0][c].lower()
                    elif letra.upper() == letra:
                        if letra == trocas[0][c]:
                            letra = trocas[1][c]
                        elif letra == trocas[1][c]:
                            letra = trocas[0][c]
                    elif letra.lower() == letra:
                        if letra.upper() == trocas[0][c]:
                            letra = trocas[1][c].lower()
                        elif letra.upper() == trocas[1][c]:
                            letra = trocas[0][c].lower()
                str += letra
            print(str)
        print()
    except:
        break