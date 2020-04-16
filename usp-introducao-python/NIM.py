def partida_ou_campeonato():  # Finished
    print ("Bem-vindo ao jogo NIM! Escolha:\n")
    print("1 - para jogar uma partida isolada")
    x=int(input("2 - para jogar um campeonato\r\n "))
    if x == 1:
        print("Você escolheu uma partida isolada!\n")
        partida()
    if x == 2:
        print("Você escolheu um campeonato!\n")
        campeonato()


def computador_escolhe_jogada(n, m):  # Finished
    if m >= n:
        v = n
        if v == 1:
            print("O computador tirou uma peça.")
        else:
            print("O computador tirou", v, "peças.")
        return v
    if m < n:
        M = False
        x = 1
        while M == False and x != m:
            mul=n-x
            if mul % (m+1)==0:
                M=True
            else:
                x=x+1
        if M==True:
            v=x
        else:
            v=m
        if v==1:
            print("O computador tirou uma peça.")
            return v
        else:
            print("O computador tirou",v,"peças.")
            return v


def usuario_escolhe_jogada(n,m): #Finished
    v=int(input("Quantas peças você vai tirar? \r\n"))
    while v>m or v>n or v<=0:
        print("Oops! Jogada inválida! Tente de novo.\n")
        v=int(input("Quantas peças você vai tirar? \r\n"))
    if v==1:
        print("Você tirou uma peça.")
    else:
        print("Você tirou",v,"peças")
    return v


def partida(): #Finished
    rodada=1
    n=int(input("Quantas peças? "))
    m=int(input("Limite de peças por jogada? "))
    while n!=0:
        if n%(m+1)==0:
            print("Voce começa!\n")
            x=0
            while x!=1 and x!=2:
                v1=usuario_escolhe_jogada(n,m)
                n=n-v1
                if n==1:
                    print("Agora resta apenas uma peça no tabuleiro.\n")
                else:
                    print("Agora restam",n,"peças no tabuleiro.\n")
                if n==0:
                    x=1
                    print("Fim do jogo! Você ganhou\n")
                    return x
                v2=computador_escolhe_jogada(n,m)
                n=n-v2
                if n==1:
                    print("Agora resta apenas uma peça no tabuleiro.\n")
                else:
                    print("Agora restam",n,"peças no tabuleiro.\n")
                if n==0:
                    print("Fim do jogo! O Computador ganhou!\n")
                    x=2
                    return x
        else:
            print("Computador começa!\n")
            x=0
            while x!=1 and x!=2:
                v2=computador_escolhe_jogada(n,m)
                n=n-v2
                if n==1:
                    print("Agora resta apenas uma peça no tabuleiro.\n")
                else:
                    print("Agora restam",n,"peças no tabuleiro.\n")
                if n==0:
                    x=2
                    print("Fim do jogo! O Computador ganhou!\n")
                    return x
                v1=usuario_escolhe_jogada(n,m)
                n=n-v1
                if n==1:
                    print("Agora resta apenas uma peça no tabuleiro.\n")
                else:
                    print("Agora restam",n,"peças no tabuleiro.\n")
                if n==0:
                    x=1
                    print("Fim do jogo! Você ganhou\n")
                    return x


def campeonato(): #finished
    i=1
    j=0
    c=0
    while i<4:
        print("**** Rodada",i,"****\n")
        v=partida()
        i=i+1
        if v==1:
            j=j+1
        if v==2:
            c=c+1
    print("**** Final do campeonato! ****\n")
    print("Placar: Você",j,"X",c,"Computador")


partida_ou_campeonato()
