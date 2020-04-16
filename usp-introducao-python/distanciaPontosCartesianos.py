import math
x=float(input("Digite a coordenada horizontal x do primeiro ponto: "))
y=float(input("Digite a coordenada vertical y do primeiro ponto: "))
X=float(input("Digite a coordenada horizontal x do segundo ponto: "))
Y=float(input("Digite a coordenada vertical y do segundo ponto: "))
catetox=abs(X-x)
catetoy=abs(Y-y)
hipotenusa=math.sqrt((catetox**2)+(catetoy**2))
if hipotenusa>=10:
    print("longe")
else:
    print("perto")

    
    
