n=int(input("Digite o valor de n: "))
contador=0
produto=n
i=1
if n==1:
    print(n)
if n==0:
    print(1)
else:
    while contador<(n-1):
        produto=produto*(n-i)
        contador=contador+1
        i=i+1
    print(produto)
    



