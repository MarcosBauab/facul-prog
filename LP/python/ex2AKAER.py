x = 0
vetor = []

while True:
  try:
    N = int(input())
    pares = 0

    for a in range (N):
      M, L = input().split()
      elemento = str(M + L)
      vetor.append(elemento)

    for b in range (30, 61):
      pe_direito = str(b) + 'D'
      pe_esquerdo = str(b) + 'E'

      if pe_direito in vetor and pe_esquerdo in vetor:
        pares = pares + 1

    print(pares)

  except EOFError:
    break