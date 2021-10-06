def imprime_linha(n1, carac1):
    for i in range(len(n1)):
        if i == len(n1) - 1:
          print(n1[i] * carac1[i])
        else:
          print(n1[i] * carac1[i], end="")

def pacman():
    for i in range(5):
      imprime_linha([10], [' '])
    imprime_linha([10, 30], [' ','#'])
    for i in range(13):
      imprime_linha([10,1,28,1], [' ','#',' ','#'])
    imprime_linha([10, 30], [' ','#'])
    for i in range(5):
      imprime_linha([10], [' '])

pacman()