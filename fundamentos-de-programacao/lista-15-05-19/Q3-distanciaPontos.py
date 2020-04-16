from math import *

entrada = ["me perdoe","por usar listas."]
origem = (0,0)
ponto = [0,0]
print("Olá! Digite os comandos no seguinte formato: ""DIREÇAO X"" --> Onde X é o número de passos.")
while entrada!=[""]: 
	entrada = input("Digite: ").split(" ")
	if len(entrada)==2 and entrada[1].isdigit()==True:
		entrada[1]=float(entrada[1])
		if entrada[0]=="CIMA":
			ponto[1]+=entrada[1]

		if entrada[0]=="BAIXO":
			ponto[1]-=entrada[1]

		if entrada[0]=="ESQUERDA":
			ponto[0]-=entrada[1]

		if entrada[0]=="DIREITA":
			ponto[0]+=entrada[1]

print("A distância é:",round(sqrt(abs(ponto[0])**2+abs(ponto[1])**2)))