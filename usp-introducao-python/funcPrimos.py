def éPrimo(n): #detecta se um número é primo ou não, é integrada na maior_primo
    i=1
    m=1
    if n==0 or n==1:
        return "não primo"
    else:
        while i<(n-1) and m!=0:
            m=n%(n-i)
            i=i+1
        if m==0:
            return "não primo"
        else:
            return "primo"
        
def maior_primo(n): #cicla de n até 0, armazena o primeiro primo na variavel
    while n>0:
        if éPrimo(n)=="primo":
            return n
        else:
            n=n-1
