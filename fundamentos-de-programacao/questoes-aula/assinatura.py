nome=input("Digite: ")
lista=nome.split(" ")
tamanho=len(lista)

corpo=""
primeiro = lista.pop(tamanho-1).upper() + ", "
t3 = lista.pop(0)

for i in lista:
	corpo = corpo + i[0].upper() + ". "

print(primeiro,t3,corpo)