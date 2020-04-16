magico = [
[8, 3, 4],
[1, 5, 9],
[6, 7, 2]
]

nao_magico = [
[5, 3, 4],
[1, 8, 9],
[6, 7, 2]
]

def analisador(matriz):
	for linha in matriz: # Somador horizontal (x)
		soma_x = 0
		for n in linha: 
			soma_x += n
		
		if matriz.index(linha) == 0: # Definidor
			magia = soma_x
		
		if magia != soma_x: # Comparador
			return False

	coluna = 0
	for coluna in range (0, len(matriz)): # Somador vertical
		soma_y = 0
		for linha in range(0, len(matriz)):
			soma_y += matriz[linha][coluna]
		
		if magia != soma_y: # Comparador
			return False

	return True

print(analisador(magico))
print(analisador(nao_magico))