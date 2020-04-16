n=(int(input("Digite um número inteiro: ")))
x=n
cont=len(str(n))
cond=False
digito=-1
n=abs(n)
while cont>0 and cond==False:
    cont=cont-1
    m=n%10
    n=n//10
    if m!=digito:
        digito=m
    else:
        cond=True
if cond==False:
    print("não")
else:
    print("sim")
        
    
