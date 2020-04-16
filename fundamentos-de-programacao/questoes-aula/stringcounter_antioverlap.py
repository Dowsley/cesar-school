padrao=input("Padrao: ")
base=input("Texto a ser comparado: ")
c=0
for i in range(len(base)):
	if base[i:i+len(padrao)] == padrao:
		c+=1
print("Dentro da frase o padrão ocorre",c,"vezes.")