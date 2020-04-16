n=int(input("Digite um número inteiro: "))
cont=len(str(n))
soma=0
while cont>0:
    m=n%10
    n=n//10
    soma=soma+m
    cont=cont-1
print(soma)
    
    
    
    
    
    
