n=int(input("Digite um número inteiro: "))
i=1
m=1
if n==0 or n==1:
    print("não primo")
else:
    while i<(n-1) and m!=0:
        m=n%(n-i)
        i=i+1
    if m==0:
        print("não primo")
    else:
        print("primo")
    
    
        
    
