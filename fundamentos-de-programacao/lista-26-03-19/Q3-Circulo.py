#Questao 3
#Input: Raio, entrada em centímetros.
#Output: Área do Circulo, diametro e comprimento da Circuferencia, msg agradável.
from math import *
r=float(input("Digite o raio da circuferência em centímetros: "))
d=r*2
a=pi*(r**2)
c=2*pi*r
print("Esse círculo possui uma área de {} cm², uma circuferência de {} cm de diâmetro e {} cm de comprimento.".format(a,d,c))


