n=int(input("Digite o valor de n: "))
cont=1
while n!=0:
    if cont%2!=0:
        print(cont)
        cont=cont+1
        n=n-1
    else:
        cont=cont+1
