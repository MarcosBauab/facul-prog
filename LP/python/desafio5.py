def imprime_linha(n1, carac1):
    for i in range(len(n1)):
        if i == len(n1) - 1:
          print(n1[i] * carac1[i])
        else:
          print(n1[i] * carac1[i], end="")

def pacman():
    imprime_linha([9,5], [' ','#'])
    imprime_linha([6,3,5,3], [' ','#',' ','#'])
    imprime_linha([4,2,11,2], [' ','#',' ','#'])
    imprime_linha([2,1,16,1], [' ','#',' ','#'])
    imprime_linha([1,1,17,2], [' ','#',' ','#'])
    imprime_linha([1,15,3], ['#',' ','#'])
    imprime_linha([1,11,3], ['#',' ','#'])
    imprime_linha([1,13,1], ['#',' ','#'])
    imprime_linha([1,15,3], ['#',' ','#'])
    imprime_linha([1,1,17,2], [' ','#',' ','#'])
    imprime_linha([2,1,16,1], [' ','#',' ','#'])
    imprime_linha([4,2,11,2], [' ','#',' ','#'])
    imprime_linha([6,3,5,3], [' ','#',' ','#'])
    imprime_linha([9,5], [' ','#'])


pacman()