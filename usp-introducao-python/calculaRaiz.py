import math
a=float(input("Digite o valor da constante a: "))
b=float(input("Digite o valor da constante b: "))
c=float(input("Digite o valor da constante c: "))
delta=(b**2)-(4*a*c)
if delta==0:
        raizunica=(-b)/(2*a)
        print("a raiz desta equação é",raizunica)
elif delta<0:
        print("esta equação não possui raízes reais")
elif delta>0:
        raizdelta=math.sqrt(delta)
        raizum=((-b)+raizdelta)/(2*a)
        raizdois=((-b)-raizdelta)/(2*a)
        if raizdois>raizum:
                print("as raízes da equação são",raizum,"e",raizdois)
        if raizum>raizdois:
                print("as raízes da equação são",raizdois,"e",raizum)
                
                
       
        
        
