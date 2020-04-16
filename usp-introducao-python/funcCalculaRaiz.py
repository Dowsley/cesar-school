import math

def delta(a,b,c):
    return (b**2)-(4*a*c)

def main():
    a=float(input("Digite o valor da constante a: "))
    b=float(input("Digite o valor da constante b: "))
    c=float(input("Digite o valor da constante c: "))
    imprime_raizes(a,b,c)

def imprime_raizes(a,b,c):
    d=delta(a,b,c)
    if d==0:
        raizunica=(-b)/(2*a)
        print("a raiz desta equação é",raizunica)
    elif d<0:
        print("esta equação não possui raízes reais")
    elif d>0:
        raizdelta=math.sqrt(d)
        raizum=((-b)+raizdelta)/(2*a)
        raizdois=((-b)-raizdelta)/(2*a)
        if raizdois>raizum:
            print("as raízes da equação são",raizum,"e",raizdois)
        if raizum>raizdois:
            print("as raízes da equação são",raizdois,"e",raizum)

main()
