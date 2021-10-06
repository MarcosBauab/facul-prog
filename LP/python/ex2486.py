while True:
    x = 0
    t = int(input())
    if t == 0:
        break
    else:
        i = 0
        vitamina_geral = 0
        while i < t:
            alimento = input().split()
            qtd = alimento[0]
            comida = ' '.join(alimento[1:])
            if comida == 'suco de laranja':
                vitamina = 120
            elif comida == 'morango fresco' or comida == 'mamao':
                vitamina = 85
            elif comida == 'goiaba vermelha':
                vitamina = 70
            elif comida == 'manga':
                vitamina = 56
            elif comida == 'laranja':
                vitamina = 50
            elif comida == 'brocolis':
                vitamina = 34
            vitamina_geral += vitamina * int(qtd)
            i += 1
        if vitamina_geral > 130:
            print("Menos %d mg" % (vitamina_geral - 130))
        elif vitamina_geral < 110:
            print("Mais %d mg" % (110 - vitamina_geral))
        else:
            print("%d mg" % vitamina_geral)



