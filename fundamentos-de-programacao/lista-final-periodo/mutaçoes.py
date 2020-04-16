def mutacoes(palavra):
	output = []
	alfa = 'abcdefghijklmnopqrstuvwxyz'
	
	for letra in alfa: # Inserção
		print(palavra + letra)
		output.append(palavra + letra)

	for letra in palavra: # Exclusão
		index = palavra.index(letra)
		mut = palavra[:index] + palavra[index+1:]
		print(mut)
		output.append(mut)

	c = 0
	for letra in palavra: # Substituição helao
		index = c
		for x in alfa:
			mut = palavra[:index] + x + palavra[index+1:]
			print(mut)
			output.append(mut)
		c += 1

	c = 0
	for letra in palavra: # Inversão hello helol
		if c != len(palavra)-1:
			index = c
			mut = palavra[:index] + palavra[index+1] + letra + palavra[index+2:]
			print(mut)
			output.append(mut)

		c += 1
	return output

words = mutacoes(input("Digite: "))

print('helo' in words)
print('cello' in words)
print('helol' in words)