altura = 5
linha = 1
while linha <= altura:
    print("*", end = "")
    coluna = 2
    while coluna < altura: 
        if linha == 1 or linha == altura:
            print("*", end="")
        else:
            print(end = " ")
        coluna = coluna + 1
    print("*")
    linha = linha + 1
