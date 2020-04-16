entrada=input("Digite: ").split(" ")
alfabeto="abcdefghijklmnopqrstuvwxyz"
saida=""
frase=""

if len(entrada) == 1:
	print("Erro.")
	passagem=False
else:
	for elemento in entrada:
		if entrada.index(elemento)>0 and not entrada.index(elemento)==(len(entrada)-1):
			frase+=elemento + " "
		if entrada.index(elemento)==(len(entrada)-1):
			frase+=elemento

	if len(entrada[0])<4:
		print("Erro.")
		passagem=False
	else:
		if "ROT" in entrada[0] and entrada[0][3:].isdigit()==True and frase.replace(" ","").isalpha()==True:
			passagem=True
		else:
			print("Erro.")
			passagem=False

if passagem==True:
	rot=int(entrada[0][3:])

	if rot==26 or rot==0:
		print(frase)
	else:
		for letra in frase:
			if letra==" ":
				saida+=letra
			else:
				if rot > 26-(alfabeto.index(letra.lower())+1):
					if letra.isupper()==True:
						saida += alfabeto[rot-(26-(alfabeto.index(letra.lower())))].upper()
					else:
						saida += alfabeto[rot-(26-(alfabeto.index(letra.lower())))]
				else:
					if letra.isupper()==True:
						saida += alfabeto[rot + alfabeto.index(letra.lower())].upper()
					else:
						saida += alfabeto[rot + alfabeto.index(letra.lower())]
	print(saida)